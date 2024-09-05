#include <stdio.h>

int main() {
    int number =1;
    int *numPointer = &number;
    // set a break point here and examine number and numpointer (whats the difference)
    int arr[10];
    // set a breakpoint here and examine some of the array indexes, ponder about what they are

    for (int i = 0; i <= 10; i++){
        //set a break point here, and examine both the array and number
        arr[i] = *numPointer;
        number += arr[i];
    }

    //printf("%d \n", *numPointer);
    // set a break point here and see what the final value of number is, is this what you would expect?
    return 1;
}