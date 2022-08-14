/*Copyraight [2021] <szapel>*/
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void sorting(int *a, int n);
void output(int *a, int n);

int main() {
    int n = 10, data[NMAX];
    if (input(data, &n) == 0) {
        sorting(data, n);
        output(data, n);
    } else {
        printf("n\a");
    }
return 0;
}
int input(int *a, int *n) {
    int fault = 0;
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) == 1) {
            } else {
                fault = fault + 1;
            }
        }
    return fault;
}


void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}
void sorting(int *a, int n) {
    double tmp;
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - j - 1; i++) {
            if (a[i] > a[i + 1]) {
                tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
            }
        }
    }
}
