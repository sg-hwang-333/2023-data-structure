#include <stdio.h>

void ShellSort(int a[], int n) {
	int i, j, key = 0, t;
	for (t = n / 2; t >= 1; t /= 2) {

		for (i = t; i < n; i++) {
			key = a[i];
			for (j = i - t; j >= 0; j-=t) {
				if (key < a[j]) a[j + t] = a[j];
				else break;
			}
			a[j + t] = key;
		}
	}
}

int main() {
	int a[] = { 3,6,7,11,12,8,5,2 };
	int n = sizeof(a) / sizeof(int);

	ShellSort(a, n);

	for (int i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");

	return 0;
}