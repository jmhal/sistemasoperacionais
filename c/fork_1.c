/*
   fork_1.c
   Um exemplo um pouco mais elaborado, mostrando como valor retornado pela
   chamada pode ser usado para diferenciar o pai e o filho.
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char*argv[]) {
   printf("Processo Pai Iniciando.\n");
   int pid;
   pid = fork();
   if (pid == 0) {                 /*filho*/
      printf("Processo filho, pid %d.\n", pid);
   } else if(pid > 0) {            /*pai*/
      printf("Processo pai, filho %d.\n", pid);
   }
   printf("Finalizando.\n");
}
