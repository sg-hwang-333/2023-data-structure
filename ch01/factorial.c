#include <stdio.h> 

// main�� �Ʒ��ʿ� �־�� �� 
int factorial(int n) {
	if (n == 1) return 1;
	return n * factorial(n - 1);
}
int main(void) {
	int n = 0;
	printf("n�� �Է��Ͻÿ� : ");
	scanf_s("%d", &n);
	printf("%d! = %d\n", n, factorial(n));

	return 0;
}