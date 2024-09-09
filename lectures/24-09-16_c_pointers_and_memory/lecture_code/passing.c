#include <stdio.h>
#include <stdint.h>
#include <string.h>


struct square {
  int height;
  int width;
};

int by_value(struct square sbv) {
  printf("\nBy value initial state:\n");
  printf("sbv.height: %d\n", sbv.height);
  printf("sbv.width: %d\n", sbv.width);

  sbv.height++;
  sbv.width++;

  printf("\nBy value ending state:\n");
  printf("sbv.height: %d\n", sbv.height);
  printf("sbv.width: %d\n", sbv.width);

  return 0;
}

int by_pointer(struct square *sbp) {
  printf("\nBy pointer initial state:\n");
  printf("sbp->height: %d\n", sbp->height);
  printf("sbp->width: %d\n", sbp->width);

  sbp->height++;
  sbp->width++;

  printf("\nBy pointer ending state:\n");
  printf("sbp->height: %d\n", sbp->height);
  printf("sbp->width: %d\n", sbp->width);

  return 0;
}

int main(void) {
  struct square sqr;
  sqr.width = 30;
  sqr.height = 30;

  printf("\nInitial state:\n");
  printf("sqr.height: %d\n", sqr.height);
  printf("sqr.width: %d\n", sqr.width);

  by_value(sqr);

  printf("\nPost by value state:\n");
  printf("sqr.height: %d\n", sqr.height);
  printf("sqr.width: %d\n", sqr.width);

  by_pointer(&sqr);

  printf("\nPost by pointer state:\n");
  printf("sqr.height: %d\n", sqr.height);
  printf("sqr.width: %d\n", sqr.width);
}