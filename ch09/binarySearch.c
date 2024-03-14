#include <stdio.h>

int binarySearch(int a[], int n, int key) {
	int left = 0, right = n - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (key == a[mid]) return mid;
		else if (key > a[mid]) left = mid + 1;
		else right = mid - 1;
	}

	return -1;
}

int main(void) {
	int i = 0, key = 0, index=0, n=0;
	int a[] = { 2,17,23,25,32,40,48,1024,1103,2222,3333,4444 };
	n = sizeof(a) / sizeof(int);
	printf("찾을 값: ");
	scanf_s("%d", &key);
	index = binarySearch(a, n, key);
	if (index >= 0) {
		printf("%d를(을) %d위치에서 찾음! \n", key, index);
	}
	else {
		printf("%d는(은) 없는 data입니다! \n", key);
	}

	return 0;
}