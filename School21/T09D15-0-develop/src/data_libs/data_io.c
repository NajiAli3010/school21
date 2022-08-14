#include "data_io.h"
#include <stdio.h>

int input(double *data, int n) {
    char c;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%lf %c", &data[i], &c) != 2){
            flag =1;
            break;
        }
    }
return flag;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%lf", data[i]);
    }
}
