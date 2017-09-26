/*
  fork_0.c
  Exemplo básico do uso da chamada de sistema fork.
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char*argv[]) {
   printf("Processo Iniciando.\n");
   int pid;
   pid = fork();
   printf("Processo Finalizando.\n");
}
