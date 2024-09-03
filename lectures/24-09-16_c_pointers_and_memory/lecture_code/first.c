#include <stdio.h>

int main() {
  char c = 'K';
  
  printf("c: %c\n", c);
  printf("&c: %p\n", &c);

  char* p = &c;

  printf("p: %p\n", p);
}
