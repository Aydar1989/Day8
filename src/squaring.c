#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n = 0;
    int data[NMAX];
    input(data, &n);
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    scanf("%d\n", n);
    for (int *p = a; p - a < *n; p++) {
        scanf("%d", p);
    }
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n - 1; p++) printf("%d ", *p);
    printf("%d", *(a + n - 1));
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) *p = *p * *p;
}
