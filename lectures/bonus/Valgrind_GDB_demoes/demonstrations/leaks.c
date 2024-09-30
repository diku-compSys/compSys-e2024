#include <stdlib.h>

int main(void) {
    int *a = malloc(500);
    int *b = malloc(1000);

    free(a);

    return 0;
}