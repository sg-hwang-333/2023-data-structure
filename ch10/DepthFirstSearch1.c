#include <stdio.h>
#define SIZE 8

int stack[SIZE] = { 0, };
int top = -1;

typedef enum { false, true } bool;

void push(int index) {
	stack[++top] = index;
}

int pop() {
	if (top == -1) return -1;
	return stack[top--];
}

void DepthFirstSearch(char v[], bool a[][SIZE]) {
	bool searchOK[SIZE] = { false, };
	int i, j;
	char vertex;

	printf("\n시작 정점(A~H 중 입력) : ");
	scanf_s("%c", &vertex, 1);

	for (i = 0; i < SIZE; i++) if (vertex == v[i]) break;

	printf("\n깊이우선탐색 순서 : %c", v[i]);

	searchOK[i] = true;

	do {
		for (j = 0; j < SIZE; j++) {
			if (a[i][j] == 1 && searchOK[j] == false) {
				printf(" -> %c", v[j]);
				push(i);
				searchOK[j] = true;
				i = j;
				break;
			}
		}

		if (j >= SIZE) i = pop();

	} while (i >= 0);
}

int main(void) {
	int i, j;
	char v[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	bool a[SIZE][SIZE] = { {0, 1, 1, 0, 0, 0, 0, 0},
			{1, 0, 0, 1, 1, 0, 0, 0},
			{1, 0, 0, 0, 0, 1, 1, 0},
			{0, 1, 0, 0, 0, 0, 0, 1},
			{0, 1, 0, 0, 0, 0, 0, 1},
			{0, 0, 1, 0, 0, 0, 0, 1},
			{0, 0, 1, 0, 0, 0, 0, 1},
			{0, 0, 0, 1, 1, 1, 1, 0} };

	/* 다음 인접행렬에 해당하는 그래프를 그려보고 깊이우선탐색을 수행하시오.
	bool a[SIZE][SIZE]={{0, 1, 1, 1, 0, 0, 0, 0},
			{1, 0, 0, 0, 1, 0, 0, 0},
			{1, 0, 0, 0, 0, 1, 0, 0},
			{1, 0, 0, 0, 0, 0, 1, 0},
			{0, 1, 0, 0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0, 0, 1, 1},
			{0, 0, 0, 1, 0, 1, 0, 1},
			{0, 0, 0, 0, 0, 1, 1, 0}};
	*/

	printf("\n\t\t인접 정점\n");
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}

	DepthFirstSearch(v, a);

	return 0;
}