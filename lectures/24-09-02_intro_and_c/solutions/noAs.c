#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        return -1;
    }
    char* s = argv[1];
    if (s[0] == 'A') {
        printf("%s\n", s);
        return 0;
    }

    printf("Does not start with A.\n");
    return -1;

}