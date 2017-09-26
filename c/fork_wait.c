/*
   fork_wait.c
   Mostra o uso da chamada waitpid.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char*argv[]) {

   int f1;
   int f2;

   printf("Olá do Pai.\n");

   f1 = fork();
   if (f1 != 0) {
      f2 = fork();
      if (f2 == 0) {
         printf ("Olá do Filho 2.\n"); 
      }
   }	 
   else {
      printf("Olá do Filho 1.\n");
   }

   if ((f1 != 0) && (f2 != 0)) {
      int status;
      waitpid(f1, &status, WUNTRACED | WCONTINUED);
      printf("Filho 1 morreu.\n");

      waitpid(f2, &status, WUNTRACED | WCONTINUED);
      printf("Filho 2 morreu.\n");
   }
   return 0;
}
