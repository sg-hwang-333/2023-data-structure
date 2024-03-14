/*
������ �������� ����Ͽ� �¿���� �� �� ������ �����ϰ� ù �湮�̸� ���� �վ� �̷θ� �����,
�湮�ߴ� ���̸� ���� ���� �ʰ� �ǳʶٸ� ��� ���� �湮�� ������ �� ������ �ݺ��Ѵ�.
�湮�ߴ� ���� �ɵ��� ��찡 ���� ȿ������ ���� ���.
*/

/*
�̷� �࿭�� ���� �����ϴ� �������
�̷� ���� ���� c, ���� r���� ������� �� ���
�̷� �࿭�� �� ũ��� (r*2 + 1), �� ũ��� (c*2 + 1)�� �غ�
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
	int i, j;
	int row, col; //���� ������ �̷� ũ��. row�� ��, col�� �� ũ��� 3 �̻��� ��
	int view_i, view_j, d, chk_cnt = 1;
	int move[4][2] = { {-2,0},{2,0},{0,-2},{0,2} };//�����¿�
	int** maze;

	do {

		printf("���� ������ �̷��� �� ũ��<3 �̻��� Ȧ��>: ");

		scanf_s("%d", &row);

		if (row >= 3 && row % 2 == 1)break;

		printf("\n�ٽ� �Է��ϼ���.\n");

	} while (1);

	do {

		printf("\n���� ������ �̷��� �� ũ��<3 �̻��� Ȧ��>: ");

		scanf_s("%d", &col);

		if (col >= 3 && col % 2 == 1)break;

		printf("\n�ٽ� �Է��ϼ���.\n");

	} while (1);

	//2���� �迭ó�� ����� maze �غ�
	maze = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++) maze[i] = (int*)malloc(sizeof(int) * col);

	//��Ž�� ����
	for (i = 0; i < row; i++)

		for (j = 0; j < col; j++)

			maze[i][j] = 0;

	srand((unsigned int)time(NULL));

	//������ ���� ��ǥ
	i = rand() % (row - 1);
	j = rand() % (col - 1);

	//¦���̸� Ȧ���� ����
	if (i % 2 == 0)i++;
	if (j % 2 == 0)j++;

	//�̷� ��
	maze[i][j] = 1;

	//��Ž�� ���� ������ �ݺ�
	while (chk_cnt < (row / 2) * (col / 2)) {

		d = (int)rand() % 4; //4���� �� ������ ����

		//���� �� ��ǥ
		view_i = i + move[d][0];
		view_j = j + move[d][1];

		//�̷� �������� �ְ�
		if (view_i >= 1 && view_i <= row - 2 && view_j >= 1 && view_j <= col - 2) {

			//��Ž���̸�
			if (maze[view_i][view_j] == 0) {

				//������ �̷η� ����
				maze[view_i][view_j] = 1;

				//Ž�� ī��Ʈ
				chk_cnt++;

				//���� ������
				switch (d) {

				case 0:maze[i - 1][j] = 1; break; //��

				case 1:maze[i + 1][j] = 1; break; //��

				case 2:maze[i][j - 1] = 1; break; //��

				case 3:maze[i][j + 1] = 1; //��

				}

			}

			//�������� ��ġ �̵�
			i = view_i;
			j = view_j;

		}

	}

	printf("\nAldous-Broder ���\n\n");

	for (i = 0; i < row; i++) {

		for (j = 0; j < col; j++) {

			if (maze[i][j] == 0) printf("��");

			else printf("��");

		}

		printf("\n");

	}

	return 0;
}