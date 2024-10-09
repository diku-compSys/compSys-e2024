#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int n = 0;

void *producer() {
  printf("Starting Producer...\n");
  int count = 0;
  while (1) {
    n = count;
    count += 1;
    sleep(1);
  }
}

void *consumer() {
  printf("Starting Consumer ...\n");
  int my_n;
  while (1)
  {
    if (n != 0) {
      my_n = n;
      n = 0;
      printf("Consumer got: %d\n", my_n);
    } else {
    }
  }  
}

int main() {
  pthread_t threads[2];
  pthread_create(&threads[0], NULL, producer, NULL);
  pthread_create(&threads[1], NULL, consumer, NULL);
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
}