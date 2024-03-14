#include <stdio.h>

#define R 3
int b[R];

void printRePer(void);  // 함수의 프로토타입(시그니처) 선언

void RePermutation(int a[], int n, int r) {
    int i;
    if (r == R)
        printRePer();
    else {
        for (i = 0; i < n; i++) {
            b[r] = a[i];
            RePermutation(a, n, r + 1);
        }
    }
}

void printRePer(void) {
    int i;
    for (i = 0; i < R; i++) {
        printf("%d\t", b[i]);
    }
    printf("\n");
}

int main(void) {
    int a[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(a) / sizeof(a[0]);

    RePermutation(a, n, 0);

    return 0;
}