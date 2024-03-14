#include <stdio.h>
#include <time.h>

int main(void) {
	clock_t t1, t2;
	int a = 0;
	
	t1 = clock();
	t2 = clock();
	while (((double)(t2 - t1) / 1000) <= 1.0){
		a++;
		printf("%d\n", a);
		t2 = clock();
	}

	printf("%.3lf초 동안 %d줄 출력", (double)(t2 - t1) / 1000, a);
}