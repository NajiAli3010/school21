/*Copyraight [2021] <szapel>*/
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main(){
    int n, data[NMAX];
    if (input(data, &n) == 0){
    squaring(data, n);
    output(data, n);
    } else {
        printf("n\a");
    }

return 0;
}
int input(int *a, int *n){
    int trash = 0;
    if (scanf("%d", n) == 1) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d",p) == 1){
            } else {
                trash = trash+1;
            }
        }
    } else {
        trash = trash+1;
    }
return trash;
}
void output(int *a, int n){
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
}

    void squaring(int *a, int n)
{
        for (int *p = a; p - a < n; p++) {
            *p = (*p)*(*p);
        }
    }
