#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n = 0;
    int data[NMAX];
    int x = input(data, &n);
    if (x == 1) {
        if (x == 1) {
            printf("n/a\n");
        }
    } else {
        squaring(data, n);
        output(data, n);
    }
    return 0;
}

int input(int *a, int *n) {
    int y, x;
    int z = 0;
    x = scanf("%d.%d\n", n, &y);
    if (x != 1 || *n <= 0 || *n > NMAX) {
        z = 1;
    } else {
        for (int *p = a; p - a < *n; p++) {
            x = scanf("%d.%d", p, &y);
            if (x != 1) {
                z = 1;
            }
        }
    }
    return z;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n - 1; p++) printf("%d ", *p);
    printf("%d", *(a + n - 1));
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) *p = *p * *p;
}