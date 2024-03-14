#include <stdio.h>

int HanoiTower(int n, char a, char b, char c) {
	static int i;
	if (n == 1) {
		printf("���� %d, %c -> %c \n", n, a, c);
	}
	else {
		HanoiTower(n-1, a, c, b);
		printf("���� %d, %c -> %c \n", n, a, c);
		HanoiTower((n - 1), b, a, c);
	}
}

int main(void) {
	char A = 'A', B = 'B', C = 'C';
	int n = 0;
	printf("�� ���� ������ �̵���Ű�ڽ��ϱ�? : ");
	scanf_s("%d", &n);

	printf("==============================\n");

	HanoiTower(n, A, B, C);
	
}