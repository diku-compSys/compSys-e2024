#include <stdio.h>

int main(void) {
  int a[5] = { 11, 12, 13, 14, 15 };

  for (int i=0; i < 5; i++) {
    printf("&a[%d] = %p\n", i, (void*)&a[i]);
    printf("a[%d] = %d\n", i, a[i]);
  }

  int *p = &a[0];

  for (int i = 0; i < 5; i++) {
    printf("i: %d, p: %p\n", i, (void*)p);
    printf("i: %d, *p: %d\n", i, *p);
    p = p + 1; // implicit * sizeof(int)
  }
}
