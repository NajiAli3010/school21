/**/
#include <stdio.h>
#include <stdlib.h>
#include "data_process.h"
#include "../data_libs/data_io.h"

int main()
{
    double *data;
    int n;
    scanf("%d", &n);
    data = (double*) malloc (sizeof(double) *n);

    input(data, n);

    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");  
    return 0;
}

