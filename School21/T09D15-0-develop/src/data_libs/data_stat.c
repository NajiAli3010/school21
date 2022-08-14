#include "data_stat.h"

double max(double *data, int n) {
    int max;
    max = *data;
    for (double *p = data; p < data + n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

double min(double *data, int n) {
    int min; 
    min = *data;
    for (double *p = data; p < data + n; p++) {
        if (*p < min) {
            min = *p; 
        }
    }
    return min;
}

double mean(double *data, int n) {
    double value = 0;
    for (double *p = data; p < data +n; p++) {
        value += *p;
    }
    return value /n;
}


double variance(double *data, int n) {
    double disp = 0;
    double sr = mean(data, n);
    for (double *p = data; p < data +n; p++) { 
        disp += (*p - sr) * (*p - sr);
    }      
    return disp /n;
}