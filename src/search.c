/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    int x = input(data, &n);
    if (x == 1) {
        printf("n/a\n");
    } else {
        output(data, n);
    }
    return 0;
}

int input(int *a, int *n) {
    int y, x;
    int z = 0;
    x = scanf("%d.%d", n, &y);
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
    int x = max(a, n);
    printf("%d", x);
}

int max(int *a, int n) {
    int max_v = *a;
    for (int *p = a; p - a < n; p++) {
        if (max_v < *p) max_v = *p;
    }
    return max_v;
}

double mean(int *a, int n) {
    double mean_v = 0;
    for (int *p = a; p - a < n; p++) {
        mean_v += *p;
    }
    mean_v = mean_v / n;

    return mean_v;
}

double variance(int *a, int n) {
    double variance_v = 0;
    double x = mean(a, n);
    for (int *p = a; p - a < n; p++) variance_v = variance_v + (((*p - x) * (*p - x)) / n);

    return variance_v;
}
