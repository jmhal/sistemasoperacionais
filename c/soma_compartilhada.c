/* 
   soma_compartilhada.c
   Exemplo de threads sem controle de exclusão mútua.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Aqui temos um ponteiro para uma função. Para passar uma função para execução dentro de um
   processo (thread), precisamos informar um ponteiro para ela. Importante notar que ela também 
   precisa receber os parâmetros como um ponteiro, no caso um ponteiro void *. */
void *soma( void *ptr );

int main(int argc, char *argv[]) {
     /* O tipo pthread_t nada mais é que um inteiro para guardar o identificar do processo. */
     pthread_t thread1, thread2;

     /* Variável compartilhada. */
     int valor = 0;

     /* Valores de retorno para criação dos processos. */
     int iret1, iret2;

     /* Criando os processos.
        Observem como transformo o endereço da variável em um ponteiro void* .*/

     iret1 = pthread_create( &thread1, NULL, soma, (void *) &valor);
     iret2 = pthread_create( &thread2, NULL, soma, (void *) &valor);

     /* Esperando ambos terminarem. */
     pthread_join(thread1, NULL);
     pthread_join(thread2, NULL); 

     /* Valor final da variável compartilhada. */ 
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
        *valor = *valor + 1;
     }
}













