#include <stdlib.h>
#include <stdio.h>

#define BAD_INPUT 0

long sum_array_cols(long *a, int N, int M)
{
  unsigned long i, j;
  long sum = 0;

  for (j = 0; j < M; j++) {
    for (i = 0; i < N; i++) {
      sum += a[i * M + j];
    }
  }
  return sum;
}

int main (int argc, char* argv[]) {
  unsigned long n,m; // Array size
  if (argc != 3) { // 2 argument
    printf("I want two ints as arguments!\n");
    return EXIT_SUCCESS;
  }
  int res;
  res = sscanf(argv[1],"%lu", &n);
  if (res == BAD_INPUT) {
    printf("I want two ints as arguments!\n");
    return EXIT_SUCCESS;
  }
  res = sscanf(argv[2],"%lu", &m);
  if (res == BAD_INPUT) {
    printf("I want two ints as arguments!\n");
    return EXIT_SUCCESS;
  }

  // Give me some memory with the size of the array
  long* input = (long*) malloc(n * m * sizeof(long));
  // Note, I do not care about the input

  // use volatile to prevent compiler from optimizing this away!
  volatile long l = sum_array_cols(input, n, m);

  printf("Sum is: %ld\n", l);

  // Give the memory back
  free(input);

  return EXIT_SUCCESS;
}
