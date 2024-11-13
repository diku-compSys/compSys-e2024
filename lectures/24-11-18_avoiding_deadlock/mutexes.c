#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_3 = PTHREAD_MUTEX_INITIALIZER;

void *threadA(void *vargp) {
    pthread_mutex_lock(&mutex_1);
    int a = 7;
    pthread_mutex_lock(&mutex_2);
    pthread_mutex_unlock(&mutex_2);
    pthread_mutex_lock(&mutex_3);
    a += 1;
    pthread_mutex_unlock(&mutex_3);
    print("hello");
    pthread_mutex_unlock(&mutex_1);
}

void *threadB(void *vargp) {
    pthread_mutex_lock(&mutex_2);
    int b=1;
    pthread_mutex_unlock(&mutex_2);
    for (int i =0; i<10; i++) {
      b = b*2;
    }
    pthread_mutex_lock(&mutex_3);
    pthread_mutex_lock(&mutex_2);
    pthread_mutex_unlock(&mutex_2);
    some_function();
    pthread_mutex_lock(&mutex_1);
    pthread_mutex_unlock(&mutex_1);
    pthread_mutex_unlock(&mutex_3);
}

int main(int argc, char **argv) {
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, threadA, NULL);
  pthread_create(&tid2, NULL, threadB, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
}
