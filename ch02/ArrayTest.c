// ���� - 15��
#include <stdio.h>

int main(void) {
	char a[] = {'P','r','a','c','t','i','c','e',' ','m','a','k','e','s',' ','p','e','r','f','e','c','t','.'};
	char b[5][10] = { {' ',' ',' ',' ','A'},{' ',' ',' ','A','B','C'},{' ',' ','A','B','C','D','E'},{' ','A','B','C','D','E','F','G'},{'A','B','C','D','E','F','G','H','I'}};

	printf("1. �迭 a �״�� ����ϱ�\n");
	for (int i = 0; i < 23; i++) {
		printf("%c", a[i]);
	}
	
	printf("\n2. �迭 a �������� ����ϱ�\n");
	for (int i = 22; i > -1; i--) {
		printf("%c", a[i]);
	}

	printf("\n3. �迭 a ���ڿ��� �� �ٿ� �ܾ ����ϱ�\n");
	for (int i = 0; i < 23; i++) {
		if (a[i] == ' ') {
			printf("\n");
		}
		else {
			printf("%c", a[i]);
		}
	}

	printf("\n4. �迭 b���� ������ ���� ����ϱ�\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (b[i][j] == ' ') continue;
			printf("%c", b[i][j]);
		}
		printf("\n");
	}

	printf("\n5. �迭 b�� �ð�������� 90�� ȸ���� ������� ����ϱ�\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 4; j > -1; j--) {
			printf("%c", b[i][j]);
		}
		printf("\n");
	}
	for (int i = 5; i < 10; i++) {
		for (int j = 4; j > -1; j--) {
			printf("%c", b[j][i]);
		}
		printf("\n");
	}
}