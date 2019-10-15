#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void quick_sort(int *a, int left, int right);

void quick_sort(int *vector, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = vector[(left + right) / 2];
     
    while(i <= j) {
        while(vector[i] < x && i < right) {
            i++;
        }
        while(vector[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = vector[i];
            vector[i] = vector[j];
            vector[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(vector, left, j);
    }
    if(i < right) {
        quick_sort(vector, i, right);
    }
}