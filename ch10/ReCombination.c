#include <stdio.h>

#define R 3
int cnt = 0;
int b[R] = { 0, };

void printReCom(void) {
	int i;
	for (i = 0; i < R; i++) {
		printf("%d\t", b[i]);
	}
	printf("\n");

	cnt++;
}

void ReCombination(int a[], int n, int r, int ii) {
	int i;

	if (r >= R) printReCom();
	else {
		for (i = ii; i < n; i++) {
			b[r] = a[i];
			ReCombination(a, n, r + 1, i);
		}
	}
}

int main(void) {
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(int);

	ReCombination(a, n, 0, 0);

	printf("중복 조합 개수: %d \n", cnt);

	return 0;
}