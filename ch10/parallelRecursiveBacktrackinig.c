//2�� �̻󿡼� ����Ͽ� Recursive Backtracking ������� �̷θ� ����� ����

/*
�̷� �࿭�� ���� �����ϴ� �������
�̷� ���� ���� c, ���� r���� ������� �� ���
�̷� �࿭�� �� ũ��� (r*2 + 1), �� ũ��� (c*2 + 1)�� �غ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define SEC_SIZE 100

typedef enum { false, true } bool;

//���� ������ �̷� ũ��. row�� ��, col�� �� ũ��� 3 �̻��� ��
int row, col;

//�̷� �� ����
struct cell {
	int r; //��
	int c; //��
	char Dir; //Ž�� ����
	int lineNo; //�̷� ��ȣ
	struct cell* link; //���� �� ����
};

//�̷� ����Ʈ ����
struct mazeList {
	int lineNo; //�̷� ��ȣ
	bool lineContact; //�ٸ� �̷ο� ���� ����
	struct cell* top; //�� �̷��� ��
};

//2���� �迭�� ¦�� ��, ���� ��, Ȧ�� ��, ���� �̷� ��
//�̷θ� ���� ��� ����� �ͷ� ȣ�� ������� ����� ����
//���� ������� ������ �̷� ũ��((��/2)*(��/2))�� 100���� ���� �� 1�� ����
//��������� ������ �������� �̷θ� ����� ������(������ ���Ḯ��Ʈ ����)�� �ٸ� �̷θ� ������ ��ġ�� ���� �Ұ��̸� �������� ���
//���������� ���� ������� ���Ͽ� �� ���ܾ� ������ ������
void mazeCreating(struct mazeList* curList, struct cell** mazeArray, int startCnt) {
	int i, j, view_i, view_j, k = 0, nullCnt = 0;
	char dir;
	int move[4][2] = { {-2,0},{2,0},{0,-2},{0,2} };//�����¿�
	struct cell* p;

	//�̷� ����� �Ϸ��� ������ �ݺ�
	while (curList != NULL) {

		//���� �̷��� �� ��ǥ
		i = curList[k].top->r;
		j = curList[k].top->c;

		if ((mazeArray[i][j].Dir & 15) < 15) { //���� ��ġ���� ���� �� ������ �����ִٸ�

			do {

				dir = (int)rand() % 4; //4���� �� ������ ����

			} while ((mazeArray[i][j].Dir & (1 << dir)) >= 1); //dir�� ���캻 �����̸� dir �ٽ� ����

			//�̵� ������ ǥ����. dir�� 3�̸� �����ʿ��� �� ��°�� 1�� �ǰ� ��. 00000100
			//4���� ��� ���캸�Ҵٸ� 00001111 => 15
			mazeArray[i][j].Dir |= (1 << dir);

			//�̵��� ���� ��ǥ�� ����
			view_i = i + move[dir][0];
			view_j = j + move[dir][1];

			//�̵��� ���� ��ǥ�� �̷� �࿭ �������� �ְ�
			if (view_i >= 1 && view_i <= row - 2 && view_j >= 1 && view_j <= col - 2) {

				//Ž���� ���� �ʾҴٸ�
				//�׸��� � �̷ο��� ������� �ʾҴٸ�(�� �� �̻��� �̷� ���� �� ��(��)�� ���� ���� �� �����Ƿ� �ݵ�� üũ)
				if (mazeArray[view_i][view_j].Dir == 0 && mazeArray[view_i][view_j].link == NULL) {

					//�̷� ���� ǥ��. ���� �㹰��
					switch (dir) {

					case 0:mazeArray[i - 1][j].Dir |= (1 << 0); break;

					case 1:mazeArray[i + 1][j].Dir |= (1 << 1); break;

					case 2:mazeArray[i][j - 1].Dir |= (1 << 2); break;

					case 3:mazeArray[i][j + 1].Dir |= (1 << 3);

					}

					mazeArray[view_i][view_j].lineNo = curList[k].lineNo; //������ ���� ���� �̷� ��ȣ ǥ��

					mazeArray[view_i][view_j].link = (mazeArray[i] + j); //���� ���� ���� �̷ο� ����

					curList[k].top = (mazeArray[view_i] + view_j); //���� ������ ������ �̵�

				}

				//�ٸ� ������� �̷θ� �����ٸ�
				else if ((curList[k].lineContact == false) && (mazeArray[i][j].lineNo != mazeArray[view_i][view_j].lineNo)) {
					p = curList[k].top;

					//���� �̷θ� �ٸ� ������� �̷ο� ������
					switch (dir) {

					case 0:mazeArray[i - 1][j].Dir |= (1 << 0); break;

					case 1:mazeArray[i + 1][j].Dir |= (1 << 1); break;

					case 2:mazeArray[i][j - 1].Dir |= (1 << 2); break;

					case 3:mazeArray[i][j + 1].Dir |= (1 << 3);

					}

					//�շ��� ǥ��
					mazeArray[i][j].Dir |= (1 << 5);

					//�ٸ� �̷ο� �շ��Ͽ����� ǥ��
					curList[k].lineContact = true;

					//���� �̷θ� �ٸ� ������� �̷ο� ��ħ
					curList[k].lineNo = mazeArray[view_i][view_j].lineNo;

					while (p != NULL) {

						p->lineNo = curList[k].lineNo;

						p = p->link;

					}

				}

			}

		}

		else { //������ ���� ���� �����(���� ��ġ�� ������)

			curList[k].top = curList[k].top->link;

		}

		//� ������� ���� �̷� ������ �Ϸ�Ǿ��ٸ� �ϷḦ ī��Ʈ��
		if (curList[k].top == NULL)nullCnt++;

		//��� ������� ���Ͽ� �̷� ������ �Ϸ��Ͽ��ٸ�
		if (nullCnt == startCnt) {

			//�̷� ����Ʈ �޸� ����
			free(curList);

			//�̷� ������ ��ĥ �غ�
			curList = NULL;

		}

		else { //�̷� ���� �ݺ�

			do {

				//���� ��������� �̵��ϰ� ���̸� ������ ����
				if (++k == startCnt)k = 0;

			} while (curList[k].top == NULL); //�̷� ������ ���� ������� �ǳʶ�
		}

	}

}

int main(void) {
	int i, j, k, startCnt;

	//2���� �迭ó�� ����ϱ� ���� �غ�. ¦�� ��, ���� ��, Ȧ�� ��, ���� �̷� ��
	struct cell** mazeArray;

	//���� ������� ���� ����Ʈ
	struct mazeList* mazeLists;

	printf("���� ������ �̷��� �� ũ��<3�̻��� Ȧ��>: ");

	do {

		scanf_s("%d", &row);

		if (row < 3 || row % 2 == 0) printf("\n�ٽ� �Է��ϼ���: ");

		else break;

	} while (1);

	printf("\n���� ������ �̷��� �� ũ��<3�̻��� Ȧ��>: ");

	do {

		scanf_s("%d", &col);

		if (col < 3 || col % 2 == 0) printf("\n�ٽ� �Է��ϼ���: ");

		else break;

	} while (1);

	//2���� �迭ó�� ����� mazeArray �غ�
	mazeArray = (struct cell**)malloc(sizeof(struct cell*) * row);

	for (i = 0; i < row; i++) mazeArray[i] = (struct cell*)malloc(sizeof(struct cell) * col);

	//��� ����� 0(��)���� ä��
	for (i = 0; i < row; i++) {

		for (j = 0; j < col; j++) {

			mazeArray[i][j].r = i;

			mazeArray[i][j].c = j;

			mazeArray[i][j].Dir = 0;

			mazeArray[i][j].link = NULL;

		}

	}

	//����� ������ ����
	startCnt = 1 + ((row / 2) * (col / 2)) / SEC_SIZE;

	srand((unsigned int)time(NULL));

	//���� ����� ����Ʈ ����
	mazeLists = (struct mazeList*)malloc(sizeof(struct mazeList) * startCnt);

	//����� ���� ��ŭ ��ǥ�� ����
	for (k = 0; k < startCnt; k++) {

		//������� ���Ƿ� ����
		i = (int)rand() % (row - 1);
		j = (int)rand() % (col - 1);

		//¦���̸� Ȧ���� ����
		if (i % 2 == 0)i++;
		if (j % 2 == 0)j++;

		//���Ḯ��Ʈ�� ���ñ����� ��������� �ϱ� ���Ͽ� ������� link�� NULL
		mazeArray[i][j].link = NULL;

		//�̷� ��ȣ ����
		mazeArray[i][j].lineNo = k;

		//����� ǥ��
		mazeArray[i][j].Dir |= (1 << 4);

		//�̷θ���Ʈ�� �̷� �� ����
		mazeLists[k].top = (mazeArray[i] + j);

		//�̷� ��ȣ ǥ��
		mazeLists[k].lineNo = k;

		//�ٸ� �̷ο� ������ X
		mazeLists[k].lineContact = false;

	}

	//���� ��� ����� �ͷ� ���(Parallel Seeds Recursive Backtracking) ȣ��
	mazeCreating(mazeLists, mazeArray, startCnt);

	//�̷θ� ����� 
	printf("\n\n������ ��� ����� �ͷ� ���(Parallel Seeds Recursive Backtracking)��");
	printf("\n\n��:�����, ��:�̷λ��� ����, ��:�ٸ� �̷ο� �շ� ����, ��:��\n\n");

	for (i = 0; i < row; i++) {

		for (j = 0; j < col; j++) {

			if (mazeArray[i][j].Dir & 16) printf("��");

			else if (mazeArray[i][j].Dir & 32) printf("��");

			else if (i % 2 == 1 && j % 2 == 1) printf("��");

			else if (mazeArray[i][j].Dir & 1) printf("��");

			else if (mazeArray[i][j].Dir & 2) printf("��");

			else if (mazeArray[i][j].Dir & 4) printf("��");

			else if (mazeArray[i][j].Dir & 8) printf("��");

			else printf("��");

		}

		printf("\n");

	}

	printf("\n\n������ ��� ����� �ͷ� ���(Parallel Seeds Recursive Backtracking)��");
	printf("\n\n��:�����, ��:��\n\n");

	for (i = 0; i < row; i++) {

		for (j = 0; j < col; j++) {

			if (mazeArray[i][j].Dir & 16) printf("��");

			else if ((i % 2 == 1 && j % 2 == 1) || mazeArray[i][j].Dir & 15) printf("��");

			else printf("��");

		}

		printf("\n");

	}

	return 0;

}