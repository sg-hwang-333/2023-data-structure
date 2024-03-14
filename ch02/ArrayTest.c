// 만점 - 15점
#include <stdio.h>

int main(void) {
	char a[] = {'P','r','a','c','t','i','c','e',' ','m','a','k','e','s',' ','p','e','r','f','e','c','t','.'};
	char b[5][10] = { {' ',' ',' ',' ','A'},{' ',' ',' ','A','B','C'},{' ',' ','A','B','C','D','E'},{' ','A','B','C','D','E','F','G'},{'A','B','C','D','E','F','G','H','I'}};

	printf("1. 배열 a 그대로 출력하기\n");
	for (int i = 0; i < 23; i++) {
		printf("%c", a[i]);
	}
	
	printf("\n2. 배열 a 역순으로 출력하기\n");
	for (int i = 22; i > -1; i--) {
		printf("%c", a[i]);
	}

	printf("\n3. 배열 a 문자열을 한 줄에 단어씩 출력하기\n");
	for (int i = 0; i < 23; i++) {
		if (a[i] == ' ') {
			printf("\n");
		}
		else {
			printf("%c", a[i]);
		}
	}

	printf("\n4. 배열 b에서 공백은 빼고 출력하기\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (b[i][j] == ' ') continue;
			printf("%c", b[i][j]);
		}
		printf("\n");
	}

	printf("\n5. 배열 b를 시계방향으로 90도 회전된 모양으로 출력하기\n");
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