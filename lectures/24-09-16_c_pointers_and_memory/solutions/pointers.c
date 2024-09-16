#include <stdio.h>

int exc1() {
    int x;
    int *p;
    p = &x;
    *p = 0;
    return x;
}

int exc2() {
    int x;
    int *p;
    int **pp;
    pp = &p;
    p = &x;
    **pp = 0;
    return x;
}

int exc3() {
    int x, y;
    int *p = &x;
    p = p;
    *p = 0;
    p = &y;
    *p = 1;
    return x;
}

int exc4() {
    int x, y;
    int* arr[2];
    arr[0] = &x;
    arr[1] = arr[0];
    *(arr[1]) = 1;
    *(arr[0]) = *(arr[0]) - 1;
}



int main() {
    int r1 = exc1();
    int r2 = exc2();
    int r3 = exc3();
    int r4 = exc4();
    printf("Exc1: %d, Exc2: %d, Exc3: %d, Exc4: %d\n", r1, r2, r3, r4);
}