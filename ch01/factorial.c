#include <stdio.h> 

// main이 아래쪽에 있어야 함 
int factorial(int n) {
	if (n == 1) return 1;
	return n * factorial(n - 1);
}
int main(void) {
	int n = 0;
	printf("n을 입력하시오 : ");
	scanf_s("%d", &n);
	printf("%d! = %d\n", n, factorial(n));

	return 0;
}