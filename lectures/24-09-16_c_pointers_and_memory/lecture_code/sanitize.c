#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(void) {
  // 01101000011001010110101000100001
  // 00100001011010100110010101101000  
  char arr[4] = { 'h', 'e', 'j', '!' };

  char *c_ptr = &arr;
  int* i_ptr = (int *)&arr;

  printf("\nChar pointer:\n");
  printf("*c_ptr: %c\n", *c_ptr);

  printf("\nInt pointer:\n");
  printf("*i_ptr: %d\n", *i_ptr);
  printf("*i_ptr+1: %d\n", *i_ptr+1);

  printf("\nChar pointer indexing:\n");
  printf("*c_ptr: %c\n", *c_ptr);
  printf("*c_ptr+1: %c\n", *c_ptr+1);
  printf("c_ptr[0]: %c\n", c_ptr[0]);
  printf("c_ptr[1]: %c\n", c_ptr[1]);

  printf("\nInt pointer indexing:\n");
  printf("*i_ptr: %d\n", *i_ptr);
  printf("*i_ptr+1: %d\n", *i_ptr+1);
  printf("i_ptr[0]: %d\n", i_ptr[0]);
  printf("i_ptr[1]: %d\n", i_ptr[1]);

  char **p_ptr = &c_ptr;

  printf("\nPointer values:\n");
  printf("c_ptr: %p\n", (void*)c_ptr);
  printf("i_ptr: %p\n", (void*)i_ptr);
  printf("p_ptr: %p\n", (void*)p_ptr);
  printf("*p_ptr: %p\n", (void*)*p_ptr);
  printf("**p_ptr: %d\n", **p_ptr);
}