/*
   semaphore.c
   Produtor-consumidor usando semáforos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>

/* Buffer */
#define N 10 
int buffer[N];
int nextWrite = 0;
int nextRead = 0;
pthread_mutex_t mutex;
sem_t items;
sem_t positions;

void *producer();
void *consumer();

int main(int argc, char *argv[]) {
   // srand(time(NULL));
    
   pthread_mutex_init(&mutex, NULL);
   sem_init(&items, 0, 0);
   sem_init(&positions, 0, N);

   pthread_t consumerID, producerID;
   pthread_create(&producerID, NULL, producer, NULL);
   pthread_create(&consumerID, NULL, consumer, NULL);

   pthread_join(producerID, NULL);
   pthread_join(consumerID, NULL); 

   pthread_mutex_destroy(&mutex);
   sem_destroy(&items);
   sem_destroy(&positions);
     
   return 0;
}

void *producer() {
   int i;
   for (i = 0; i < 2 * N; i++) {
      // sleep(rand() % 10);
      printf("Producer: Starting step %d.\n", i);

      printf("Producer: Verifying free positions on the buffer.\n");
      sem_wait(&positions);

      printf("Producer: Free positions available. Waiting for mutual exclusion.\n");
      pthread_mutex_lock(&mutex);

      int newItem = rand() % 100;
      printf("Producer: New item %d on position %d.\n", newItem, nextWrite); 
      buffer[nextWrite] = newItem;
      nextWrite = (nextWrite + 1) % N;

      printf("Producer: Leaving critical region.\n");
      pthread_mutex_unlock(&mutex);
    
      printf("Producer: Signal available items to Consumer.\n");
      sem_post(&items);
   }
}

void *consumer() {
   int i;
   for (i = 0; i < 2 * N; i++) {
      // sleep(rand() % 10);
      printf("Consumer: Starting step %d.\n", i);

      printf("Consumer: Verifying items on the buffer.\n");
      sem_wait(&items);

      printf("Consumer: Items available. Waiting for mutual exclusion.\n");
      pthread_mutex_lock(&mutex);

      int newItem =  buffer[nextRead];
      printf("Consumer: New item %d from position %d.\n", newItem, nextRead);
      nextRead = (nextRead + 1) % N;

      printf("Consumer: Leaving critical region.\n");
      pthread_mutex_unlock(&mutex);
      
      printf("Consumer: Signal available positions to Producer.\n");
      sem_post(&positions);
   }
}

















