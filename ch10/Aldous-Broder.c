/*
임의의 지점에서 출발하여 좌우상하 중 한 방향을 선택하고 첫 방문이면 벽을 뚫어 미로를 만들고,
방문했던 곳이면 길을 내지 않고 건너뛰며 모든 셀을 방문할 때까지 이 과정을 반복한다.
방문했던 곳을 맴도는 경우가 많아 효율성이 낮은 방법.
*/

/*
미로 행열에 벽을 포함하는 방법으로
미로 방을 가로 c, 세로 r개로 만들고자 할 경우
미로 행열은 행 크기는 (r*2 + 1), 열 크기는 (c*2 + 1)로 준비
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
	int i, j;
	int row, col; //벽을 포함한 미로 크기. row는 행, col은 열 크기로 3 이상의 값
	int view_i, view_j, d, chk_cnt = 1;
	int move[4][2] = { {-2,0},{2,0},{0,-2},{0,2} };//상하좌우
	int** maze;

	do {

		printf("벽을 포함한 미로의 행 크기<3 이상의 홀수>: ");

		scanf_s("%d", &row);

		if (row >= 3 && row % 2 == 1)break;

		printf("\n다시 입력하세요.\n");

	} while (1);

	do {

		printf("\n벽을 포함한 미로의 열 크기<3 이상의 홀수>: ");

		scanf_s("%d", &col);

		if (col >= 3 && col % 2 == 1)break;

		printf("\n다시 입력하세요.\n");

	} while (1);

	//2차원 배열처럼 사용할 maze 준비
	maze = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++) maze[i] = (int*)malloc(sizeof(int) * col);

	//미탐색 설정
	for (i = 0; i < row; i++)

		for (j = 0; j < col; j++)

			maze[i][j] = 0;

	srand((unsigned int)time(NULL));

	//임의의 시작 좌표
	i = rand() % (row - 1);
	j = rand() % (col - 1);

	//짝수이면 홀수로 변경
	if (i % 2 == 0)i++;
	if (j % 2 == 0)j++;

	//미로 방
	maze[i][j] = 1;

	//미탐색 방이 있으면 반복
	while (chk_cnt < (row / 2) * (col / 2)) {

		d = (int)rand() % 4; //4방향 중 임의의 방향

		//인접 방 좌표
		view_i = i + move[d][0];
		view_j = j + move[d][1];

		//미로 범위내에 있고
		if (view_i >= 1 && view_i <= row - 2 && view_j >= 1 && view_j <= col - 2) {

			//미탐색이면
			if (maze[view_i][view_j] == 0) {

				//인접을 미로로 설정
				maze[view_i][view_j] = 1;

				//탐색 카운트
				chk_cnt++;

				//벽을 제거함
				switch (d) {

				case 0:maze[i - 1][j] = 1; break; //상

				case 1:maze[i + 1][j] = 1; break; //하

				case 2:maze[i][j - 1] = 1; break; //좌

				case 3:maze[i][j + 1] = 1; //우

				}

			}

			//인접으로 위치 이동
			i = view_i;
			j = view_j;

		}

	}

	printf("\nAldous-Broder 방법\n\n");

	for (i = 0; i < row; i++) {

		for (j = 0; j < col; j++) {

			if (maze[i][j] == 0) printf("▦");

			else printf("　");

		}

		printf("\n");

	}

	return 0;
}