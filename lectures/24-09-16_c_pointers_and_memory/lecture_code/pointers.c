#include <stdio.h>

int main(void) {
  int x = 2;
  printf("x: %d\n", x);
  printf("&x: %p\n", (void*)&x);

  int* px = &x;

  // x has type T
  // &x has type T*
  printf("px: %p\n", (void*)px);
  printf("&px: %p\n", (void*)&px); // int**

  *px = 5;

  printf("x: %d\n", x);
}
