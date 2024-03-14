#include <stdio.h>

#define R 3
int b[R] = { 0, }, cnt = 0;

void printRePer(void) {
    int i;

    for (i = 0; i < R; i++) {
        printf("%d\t", b[i]);
    }
    printf("\n"); cnt++;
}

void exchange(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void RePermutation(int a[], int n, int r) {
    int i;
    if (r >= R)
        printRePer();
    else {
        for (i = r; i < n; i++) {
            exchange(a + r, a + i);
            b[r] = a[r];
            RePermutation(a, n, r + 1);
            exchange(a + r, a + i);
        }
    }
}

int main(void) {
    int a[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(a) / sizeof(a[0]);

    RePermutation(a, n, 0);
    printf("중복순열 개수 : %d\n", cnt);

    return 0;
}