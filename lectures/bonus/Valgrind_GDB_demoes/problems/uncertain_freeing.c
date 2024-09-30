#include <stdlib.h>
#include <stdio.h>

int n = 10;
int* a = NULL;
int* b = NULL;
int* c = NULL;
long int checksum = 0;

void count(int* arr) {
    for (int i=0; i<n; i++) {
        checksum += arr[i];
    }
}

void func1(){
    int used_a = 0;
    int used_b = 0;
    int used_c = 0;
    if (checksum == 0) {
        count(a);
        used_a = 1;
    } else {
        if (checksum % 10 == 0) {
            count(c);
            used_c = 1;
        }
        else {
            count(b);
            used_b = 1;
            if (1000000 - checksum < 0) {
                count(c);
                used_c = 1;
            }
        }
    }
}

void func2(){
    int used_a = 0;
    int used_b = 0;
    int used_c = 0;
    if (checksum == 0) {
        count(b);
        used_b = 1;
    } else {
        if (checksum % 5 == 0) {
            count(b);
            used_b = 1;
        }
        if (checksum < (254*254)) {
            count(a);
            used_a = 1;
        }
    }
}

void func3(){
    int used_a = 0;
    int used_b = 0;
    int used_c = 0;
    if (checksum != 0) {
        count(c);
        used_c = 1;
        if (checksum > 100) {
            if (checksum % 10) {
                count(a);
                used_a = 1;
            } else {
                if (checksum + checksum > 10000) {
                    count(b);
                    used_b = 1;
                }
            }
        }
    } else {
        if (checksum % 5 == 0) {
            count(b);
            used_b = 1;
        } else {
            count(a);
            used_a = 1;
        }
    
    }
}

int main(void) {
    a = malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        a[i] = i;
    }
    b = malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        b[i] = i*10;
    }
    c = malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        c[i] = i*100;
    }

    // You can only add free statements below here and should do so are early as
    // possible without altering the result
    func1();
    func3();
    func2();
    func3();
    func2();
    func3();
    func3();
    func2();
    func2();
    func3();
    func2();
    func3();
    func1();
    func2();
    func3();
    func2();
    func3();
    func1();
    func1();
    func3();
    func1();
    func2();
    func1();
    func2();

    if (checksum != 65025)
        printf("You've altered functionality\n");
    printf("%ld\n", checksum);

    return 0;
}