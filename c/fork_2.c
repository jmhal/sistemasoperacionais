/*
   fork_2.c
   Aqui, usamos uma variável para realçar a diferença entre pai e filho.
*/
#include <stdio.h>

int num = 0;
int main(int argc, char*argv[]){
   int pid;
   pid = fork();
   printf("%d", num);  
   if (pid == 0){       /*child*/
      num = 1;
   }else if(pid > 0){   /*parent*/
      num = 2;
   }
   printf("%d", num);
}
