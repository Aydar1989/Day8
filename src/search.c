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
#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int max(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int treb(int *a, int n);

int main() {
    int n, data[NMAX];
    int x = input(data, &n);
    if (x == 1) {
        printf("n/a\n");
    } else {
        int z = treb(data, n);
        printf("%d", z);
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

int treb(int *a, int n) {
    double x = mean(a, n);
    double y = variance(a, n);
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0 && *p >= x && *p <= x + 3 * sqrt(y) && *p != 0) return *p;
    }
    return 0;
}