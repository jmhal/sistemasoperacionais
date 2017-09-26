/*
   mutex.c
   O uso do mutex para garantir exclusão mútua.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;

void *soma( void *ptr );

int main(int argc, char *argv[]) {
     pthread_t thread1, thread2;

     int valor = 0;

     if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Falha ao iniciar o mutex. \n");
	return 1;
     }

     int iret1, iret2;

     iret1 = pthread_create( &thread1, NULL, soma, (void *) &valor);
     iret2 = pthread_create( &thread2, NULL, soma, (void *) &valor);

     pthread_join(thread1, NULL);
     pthread_join(thread2, NULL); 

     pthread_mutex_destroy(&lock);

     printf("Valor: %d.\n", valor);

     return 0;
}

/* Definição da função. */
void *soma( void *ptr )
{
     int *valor;
     /* Converto de volta para int * a partir de void * .*/
     valor = (int *) ptr;
     for (int i = 0; i < 1000; i++) {
        /* Operação down no mutex.*/
        pthread_mutex_lock(&lock);

        *valor = *valor + 1; /* Região Crítica. */

	/* Operação up no mutex.*/
	pthread_mutex_unlock(&lock);
     }
}

















