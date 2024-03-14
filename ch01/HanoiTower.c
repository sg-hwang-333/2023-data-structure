#include <stdio.h>

int HanoiTower(int n, char a, char b, char c) {
	static int i;
	if (n == 1) {
		printf("원판 %d, %c -> %c \n", n, a, c);
	}
	else {
		HanoiTower(n-1, a, c, b);
		printf("원판 %d, %c -> %c \n", n, a, c);
		HanoiTower((n - 1), b, a, c);
	}
}

int main(void) {
	char A = 'A', B = 'B', C = 'C';
	int n = 0;
	printf("몇 개의 원판을 이동시키겠습니까? : ");
	scanf_s("%d", &n);

	printf("==============================\n");

	HanoiTower(n, A, B, C);
	
}