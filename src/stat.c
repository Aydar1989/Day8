#include <stdio.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int x = input(data, &n);
        if (x == 1) {
            printf("n/a\n");
        }
        else {
            output(data, n);
            output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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
    for(int *p = a; p - a < n- 1; p++) {
        printf("%d ", *p);
    }
        printf("%d\n", *(a + n - 1));
}


int max(int *a, int n) {
   int max_v = *a;
    for (int *p = a; p - a < n; p++) {
        if (max_v < *p)
            max_v = *p;
    }
    return max_v;
}



int min(int *a, int n) {
    int min_v = *a;
    for (int *p = a; p - a < n; p++) {
        if (min_v > *p)
            min_v = *p;
    }
return min_v;

}


double mean(int *a, int n) {
    double mean_v = 0;
    for (int *p = a; p - a < n ; p++) { 
        mean_v += *p;
    }
    mean_v = mean_v / n;

return mean_v;
}


double variance(int *a, int n) {
    double variance_v = 0;
    double x = mean(a, n);
    for (int *p = a; p - a < n ; p++) 
            variance_v = variance_v + (((*p - x) * (*p - x)) / n);

return variance_v;
}


void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %0.6lf %0.6lf", max_v, min_v, mean_v, variance_v);
}