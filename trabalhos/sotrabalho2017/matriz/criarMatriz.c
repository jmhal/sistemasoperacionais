#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
   // Recuperar ordem da matriz.
   int ordem = atoi(argv[1]);

   // Recuperar nome do arquivo para salvar a matriz.
   char *nomeDoArquivo = argv[2];

   // Abrir arquivo para escrita.
   FILE *arquivo = fopen(nomeDoArquivo, "w+");

   // Faixa de valores aleatórios
   srand((unsigned int)time(NULL));
   float faixaAleatoria = 100.00;

   // Escreve a ordem.
   fprintf(arquivo, "%d\n", ordem);
   for (int i = 0; i < ordem; i++) {
      for (int j = 0; j < ordem; j++) {
         float valorAleatorio = ((float)rand()/(float)(RAND_MAX)) * faixaAleatoria;
         if (j < ordem - 1)
            fprintf(arquivo, "%.2f:", valorAleatorio);
	 else 
            fprintf(arquivo, "%.2f", valorAleatorio);
      }
      fprintf(arquivo, "\n");
   }

   // Escreve os elementos.

   // Fecha arquivo.
   fclose(arquivo);

   return 0;
}
