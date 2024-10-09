#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int n = 0;
pthread_mutex_t lock; 

void *producer() {
  printf("Starting Producer...\n");
  int count = 0;
  while (1) {
    n = count;
    count += 1;
    sleep(1);
  }
}

void *consumer(void *vargp) {
  int id = (int*)vargp;
  printf("Starting Consumer %d ...\n", id);
  int my_n;
  while (1)
  {
    pthread_mutex_lock(&lock); 
    if (n != 0) {
      my_n = n;
      n = 0;
      pthread_mutex_unlock(&lock); 
      printf("Consumer %d got: %d\n", id, my_n);
    } else {
      pthread_mutex_unlock(&lock); 
    }
  }  
}

int main() {
  pthread_t threads[3];
  pthread_mutex_init(&lock, NULL);
  pthread_create(&threads[0], NULL, producer, NULL);
  pthread_create(&threads[1], NULL, consumer, (void*)1);
  pthread_create(&threads[2], NULL, consumer, (void*)2);
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);
}