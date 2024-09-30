#include <stdlib.h>

int m = 5;
int n = 100;

void init(int* arr, int num) {
    for (int i=0; i<n; i++) {
        arr[i] = i + num;
    }
}

int main(void) {
    int **all = malloc(m * sizeof(int*));
    for (int i=0; i<m; i++) {
        int *arr = malloc(n * sizeof(int));
        init(arr, i);
        all[i] = arr;
    }

    // You're only allowed to free below this line

    return 0;
}