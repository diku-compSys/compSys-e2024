#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 8

int main(int argc, char* argv[]) {
    srand(time(NULL));

    // Validate arguments if present
    int lower_limit = 0;
    int upper_limit = 10;
    if (argc == 2) {
        if (sscanf(argv[1], "%d", &upper_limit) != 1) {
            printf("invalid argument, not a number\n");
            return -1;
        }
    }
    else if (argc > 2) {
        if (sscanf(argv[1], "%d", &lower_limit) != 1) {
            printf("invalid argument, not a number\n");
            return -1;
        }
        if (sscanf(argv[2], "%d", &upper_limit) != 1) {
            printf("invalid argument, not a number\n");
            return -1;
        }
    }
    // Ensure that lower limit is indeed less than upper limit
    if (lower_limit > upper_limit) {
        int temp = lower_limit;
        lower_limit = upper_limit;
        upper_limit = temp;
    }

    int tries = 1;
    int answer = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    char input_buffer[MAX_DIGITS];

    printf("make a guess between %d and %d inclusive\n", lower_limit, upper_limit);
    while (1) {
        // Read up to MAX_DIGITS or newline then validate guess
        int guess;
        fgets(input_buffer, MAX_DIGITS, stdin);

        // We only read MAX_DIGITS at a time,
        // so inputs longer than that need to be cleared manually
        if (strchr(input_buffer, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        if (sscanf(input_buffer, "%d", &guess) != 1) {
            printf("not a number, guess again\n");
            continue;
        }
        if (guess < lower_limit || guess > upper_limit) {
            printf("guess is out of bounds\n");
            continue;
        }

        if (guess < answer) {
            printf("too low\n");
        }
        else if (guess > answer) {
            printf("too high\n");
        }
        else {
            printf("correct! took %d tries\n", tries);
            return 0;
        }

        tries += 1;
    }

    return 0;
}
