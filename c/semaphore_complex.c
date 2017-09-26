#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>


struct sharedBuffer 
{
   int *data;
   int size;
   int steps;
   int nextRead;
   int nextWrite;
   pthread_mutex_t mutex;
   sem_t items;
   sem_t positions;
}

void *producer(void *ptr);
void *consumer(void *ptr);

int main(int argc, char *argv[]) {
     int bufferSize = atoi(argv[1])
     int randomInterval = atoi(argv[2])
     int numberOfItems = atoi(argv[3]) 
  
     printf("bufferSize=%d; randomInterval=%d; numberOfItems=%d", bufferSize, randomInterval, numberOfItems);
     srand(time(null));

     struct sharedBuffer buffer;
     buffer.data = malloc(bufferSize * sizeof(int));
     buffer.size = bufferSize;
     buffer.steps = numberOfItems;
     buffer.nextRead = 0;
     buffer.nextWrite = 0;
    
     pthread_mutex_init(&buffer.mutex, NULL);
     sem_init(&(buffer.items), 0, 0);
     sem_init(&(buffer.positions), 10, bufferSize);

     pthread_t consumerID, producerID;
     pthread_create(&producerID, NULL, producer, (void *) &buffer);
     pthread_create(&consumerID, NULL, consumer, (void *) &buffer);

     pthread_join(producerID, NULL);
     pthread_join(consumerID, NULL); 

     pthread_mutex_destroy(&buffer.mutex);
     sem_destroy(&(buffer.items));
     sem_destroy(&(buffer.positions));

     free(buffer->data);
     return 0;
}

/* Definição da função. */
void *producer(void *ptr)
{
    struct sharedBuffer *buffer;
    buffer = (sharedBuffer *) ptr;

    int i;
    for (i = 0; i < buffer->steps; i++) {
       printf("Producer: Starting step %d.", i);
       sem_wait(&(buffer->positions));
       pthread_mutex_lock(&(buffer->mutex));

       newItem = 
       buffer->data[buffer->nextWrite] = newItem;
       buffer->nextWrite = (buffer->nextWrite + 1) % buffer->size;

       pthread_mutex_unlock(&(buffer->mutex));
       sem_post(&(buffer->items));
    }
}

















