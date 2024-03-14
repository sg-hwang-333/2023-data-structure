#include <stdio.h>

void InsertionSort(int a[], int n) {
	int i, j, key=0;
	for (i = 0; i < n; i++) {
		key = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (key < a[j]) a[j + 1] = a[j];
			else break;
		}
		a[j + 1] = key;
	}
}

int main() {
	int a[] = { 3,6,7,11,12,8,5,2 };
	int n = sizeof(a) / sizeof(int);

	InsertionSort(a, n);

	for (int i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");

	return 0;
}