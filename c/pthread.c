/*
   phtread.c 
   Exemplo básico de pthread. Para compilar, devemos adicionar a diretiva -lpthread ao final do 
   comando do gcc.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message_function( void *ptr );

int main()
{
     pthread_t thread1, thread2;
     char *message1 = "Thread 1";
     char *message2 = "Thread 2";
     int  iret1, iret2;

     iret1 = pthread_create( &thread1, NULL, print_message_function, (void *) message1);
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void *) message2);

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("Thread %u retorna: %d\n", (int) thread1, iret1);
     printf("Thread %u retorna: %d\n", (int) thread2, iret2);
     exit(0);
}

void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}
