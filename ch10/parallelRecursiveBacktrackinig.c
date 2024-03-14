//2곳 이상에서 출발하여 Recursive Backtracking 방법으로 미로를 만들어 나감

/*
미로 행열에 벽을 포함하는 방법으로
미로 방을 가로 c, 세로 r개로 만들고자 할 경우
미로 행열은 행 크기는 (r*2 + 1), 열 크기는 (c*2 + 1)로 준비
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define SEC_SIZE 100

typedef enum { false, true } bool;

//벽을 포함한 미로 크기. row는 행, col은 열 크기로 3 이상의 값
int row, col;

//미로 방 정보
struct cell {
	int r; //행
	int c; //열
	char Dir; //탐색 방향
	int lineNo; //미로 번호
	struct cell* link; //다음 방 연결
};

//미로 리스트 정보
struct mazeList {
	int lineNo; //미로 번호
	bool lineContact; //다른 미로와 접선 여부
	struct cell* top; //한 미로의 끝
};

//2차원 배열의 짝수 행, 열은 벽, 홀수 행, 열은 미로 방
//미로를 다중 출발 재귀적 귀로 호출 방법으로 만들어 나감
//다중 출발점의 개수는 미로 크기((행/2)*(열/2))를 100으로 나눈 몫에 1을 더함
//출발점에서 임의의 방향으로 미로를 만들어 나가다(역방향 연결리스트 구성)가 다른 미로를 만나면 합치고 전진 불가이면 이전으로 재귀
//생성과정을 다중 출발점에 대하여 한 스텝씩 번갈아 진행함
void mazeCreating(struct mazeList* curList, struct cell** mazeArray, int startCnt) {
	int i, j, view_i, view_j, k = 0, nullCnt = 0;
	char dir;
	int move[4][2] = { {-2,0},{2,0},{0,-2},{0,2} };//상하좌우
	struct cell* p;

	//미로 만들기 완료할 때까지 반복
	while (curList != NULL) {

		//현재 미로의 끝 좌표
		i = curList[k].top->r;
		j = curList[k].top->c;

		if ((mazeArray[i][j].Dir & 15) < 15) { //현재 위치에서 살펴 볼 방향이 남아있다면

			do {

				dir = (int)rand() % 4; //4방향 중 임의의 방향

			} while ((mazeArray[i][j].Dir & (1 << dir)) >= 1); //dir이 살펴본 방향이면 dir 다시 구함

			//이동 방향을 표시함. dir이 3이면 오른쪽에서 세 번째가 1이 되게 함. 00000100
			//4방향 모두 살펴보았다면 00001111 => 15
			mazeArray[i][j].Dir |= (1 << dir);

			//이동할 방의 좌표를 구함
			view_i = i + move[dir][0];
			view_j = j + move[dir][1];

			//이동할 방의 좌표가 미로 행열 범위내에 있고
			if (view_i >= 1 && view_i <= row - 2 && view_j >= 1 && view_j <= col - 2) {

				//탐색을 하지 않았다면
				//그리고 어떤 미로에도 연결되지 않았다면(두 개 이상의 미로 끝이 한 방(셀)을 보고 있을 수 있으므로 반드시 체크)
				if (mazeArray[view_i][view_j].Dir == 0 && mazeArray[view_i][view_j].link == NULL) {

					//미로 방향 표시. 벽을 허물고
					switch (dir) {

					case 0:mazeArray[i - 1][j].Dir |= (1 << 0); break;

					case 1:mazeArray[i + 1][j].Dir |= (1 << 1); break;

					case 2:mazeArray[i][j - 1].Dir |= (1 << 2); break;

					case 3:mazeArray[i][j + 1].Dir |= (1 << 3);

					}

					mazeArray[view_i][view_j].lineNo = curList[k].lineNo; //전진할 방을 현재 미로 번호 표시

					mazeArray[view_i][view_j].link = (mazeArray[i] + j); //다음 방은 현재 미로에 연결

					curList[k].top = (mazeArray[view_i] + view_j); //끝을 연결한 방으로 이동

				}

				//다른 출발점의 미로를 만났다면
				else if ((curList[k].lineContact == false) && (mazeArray[i][j].lineNo != mazeArray[view_i][view_j].lineNo)) {
					p = curList[k].top;

					//현재 미로를 다른 출발점의 미로와 연결함
					switch (dir) {

					case 0:mazeArray[i - 1][j].Dir |= (1 << 0); break;

					case 1:mazeArray[i + 1][j].Dir |= (1 << 1); break;

					case 2:mazeArray[i][j - 1].Dir |= (1 << 2); break;

					case 3:mazeArray[i][j + 1].Dir |= (1 << 3);

					}

					//합류점 표시
					mazeArray[i][j].Dir |= (1 << 5);

					//다른 미로와 합류하였음을 표시
					curList[k].lineContact = true;

					//현재 미로를 다른 출발점의 미로와 합침
					curList[k].lineNo = mazeArray[view_i][view_j].lineNo;

					while (p != NULL) {

						p->lineNo = curList[k].lineNo;

						p = p->link;

					}

				}

			}

		}

		else { //전진할 곳이 없어 재귀함(이전 위치로 후진함)

			curList[k].top = curList[k].top->link;

		}

		//어떤 출발점에 대한 미로 생성이 완료되었다면 완료를 카운트함
		if (curList[k].top == NULL)nullCnt++;

		//모든 출발점에 대하여 미로 생성이 완료하였다면
		if (nullCnt == startCnt) {

			//미로 리스트 메모리 해제
			free(curList);

			//미로 생성을 마칠 준비
			curList = NULL;

		}

		else { //미로 생성 반복

			do {

				//다음 출발점으로 이동하고 끝이면 앞으로 돌림
				if (++k == startCnt)k = 0;

			} while (curList[k].top == NULL); //미로 생성이 끝난 출발점은 건너뜀
		}

	}

}

int main(void) {
	int i, j, k, startCnt;

	//2차원 배열처럼 사용하기 위해 준비. 짝수 행, 열은 벽, 홀수 행, 열은 미로 방
	struct cell** mazeArray;

	//다중 출발점에 대한 리스트
	struct mazeList* mazeLists;

	printf("벽을 포함한 미로의 행 크기<3이상의 홀수>: ");

	do {

		scanf_s("%d", &row);

		if (row < 3 || row % 2 == 0) printf("\n다시 입력하세요: ");

		else break;

	} while (1);

	printf("\n벽을 포함한 미로의 열 크기<3이상의 홀수>: ");

	do {

		scanf_s("%d", &col);

		if (col < 3 || col % 2 == 0) printf("\n다시 입력하세요: ");

		else break;

	} while (1);

	//2차원 배열처럼 사용할 mazeArray 준비
	mazeArray = (struct cell**)malloc(sizeof(struct cell*) * row);

	for (i = 0; i < row; i++) mazeArray[i] = (struct cell*)malloc(sizeof(struct cell) * col);

	//모든 방들을 0(벽)으로 채움
	for (i = 0; i < row; i++) {

		for (j = 0; j < col; j++) {

			mazeArray[i][j].r = i;

			mazeArray[i][j].c = j;

			mazeArray[i][j].Dir = 0;

			mazeArray[i][j].link = NULL;

		}

	}

	//출발점 개수를 구함
	startCnt = 1 + ((row / 2) * (col / 2)) / SEC_SIZE;

	srand((unsigned int)time(NULL));

	//다중 출발점 리스트 생성
	mazeLists = (struct mazeList*)malloc(sizeof(struct mazeList) * startCnt);

	//출발점 개수 만큼 좌표를 구함
	for (k = 0; k < startCnt; k++) {

		//출발점을 임의로 정함
		i = (int)rand() % (row - 1);
		j = (int)rand() % (col - 1);

		//짝수이면 홀수로 변경
		if (i % 2 == 0)i++;
		if (j % 2 == 0)j++;

		//연결리스트로 스택구조가 만들어지게 하기 위하여 출발점의 link는 NULL
		mazeArray[i][j].link = NULL;

		//미로 번호 저장
		mazeArray[i][j].lineNo = k;

		//출발점 표시
		mazeArray[i][j].Dir |= (1 << 4);

		//미로리스트에 미로 끝 설정
		mazeLists[k].top = (mazeArray[i] + j);

		//미로 번호 표시
		mazeLists[k].lineNo = k;

		//다른 미로와 접선은 X
		mazeLists[k].lineContact = false;

	}

	//다중 출발 재귀적 귀로 방법(Parallel Seeds Recursive Backtracking) 호출
	mazeCreating(mazeLists, mazeArray, startCnt);

	//미로를 출력함 
	printf("\n\n【다중 출발 재귀적 귀로 방법(Parallel Seeds Recursive Backtracking)】");
	printf("\n\n●:출발점, →:미로생성 방향, ⊙:다른 미로와 합류 지점, ▦:벽\n\n");

	for (i = 0; i < row; i++) {

		for (j = 0; j < col; j++) {

			if (mazeArray[i][j].Dir & 16) printf("●");

			else if (mazeArray[i][j].Dir & 32) printf("⊙");

			else if (i % 2 == 1 && j % 2 == 1) printf("　");

			else if (mazeArray[i][j].Dir & 1) printf("↑");

			else if (mazeArray[i][j].Dir & 2) printf("↓");

			else if (mazeArray[i][j].Dir & 4) printf("←");

			else if (mazeArray[i][j].Dir & 8) printf("→");

			else printf("▦");

		}

		printf("\n");

	}

	printf("\n\n【다중 출발 재귀적 귀로 방법(Parallel Seeds Recursive Backtracking)】");
	printf("\n\n●:출발점, ▦:벽\n\n");

	for (i = 0; i < row; i++) {

		for (j = 0; j < col; j++) {

			if (mazeArray[i][j].Dir & 16) printf("●");

			else if ((i % 2 == 1 && j % 2 == 1) || mazeArray[i][j].Dir & 15) printf("　");

			else printf("▦");

		}

		printf("\n");

	}

	return 0;

}