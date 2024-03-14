#include <stdio.h>

int main(void) {
	int i, j, b[5][3];
	int a[3][5] = { {5,41,24,6,10},
					{50,33,2,15,11},
					{7,17,35,21,16} };

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			b[j][i] = a[i][j];
		}
	}

	printf("======== 배열 a ========\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			printf("%2d	", a[i][j]);
		}
		printf("\n");
	}

	int count = 0;
	printf("\n======== 배열 b ========\n");
	for (i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%2d	", b[i][j]);
			count++;
		}
		printf("\n");
	}
} 