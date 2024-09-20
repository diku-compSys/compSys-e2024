#include <pthread.h>
#include <assert.h>
#include <stdio.h>

void* thread(void *arg) {
  int* p = arg;
  printf("Starting thread %d\n", *p);
  for (int i=0; i<1000000000; i++) {
    int a=i*i;
  }
  printf("Thread %d done\n", *p);
  return NULL;
}

int main(void) {
  int x = 1;
  int y = 2;
  pthread_t tid1;
  pthread_t tid2;
  assert(pthread_create(&tid1, NULL, thread, &x) == 0);
  assert(pthread_create(&tid2, NULL, thread, &y) == 0);
  assert(pthread_join(tid1, NULL) == 0);
  assert(pthread_join(tid2, NULL) == 0);
}
