#include <stdio.h>

int* func(int* b) {
    printf("Array size is: %ld, %d\n", sizeof(*b), b[2]);
    
    int c[5] = { 21, 22, 23, 24, 25 };
    
    return c;
}

int main(void) {
    int a[5] = { 11, 12, 13, 14, 15 };
    printf("Array size is: %ld, %d\n", sizeof(a), a[2]);

    int* d = func(&a);

    printf("Array size is: %ld, %d\n", sizeof(d), d[2]);
}
