# Programas Auxiliares

Nesta pasta estão dois programas em C que auxiliam na definição de matrizes para testar a execução dos trabalhos.

## criarMatriz.c

Este programa cria um arquivo com uma matriz quadrada formada apenas por elementos iguais a 1.0. Passos para execução no terminal do Linux:

```
$ gcc criarMatriz.c -o criarMatriz
$ ./criarMatriz 10 matriz10x10_A.txt
$ cat matriz10x10_A.txt 
10
1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00
1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00
1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00
1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00
1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00
1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00
1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00
1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00
1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00
1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00:1.00
```

## comparaMatrizes.c

Este programa compara dois arquivos de matrizes e indica se elas são iguais ou diferentes.

```
$ gcc comparaMatrizes.c -o comparaMatrizes
$ cp matriz10x10_A.txt matriz10x10_B.txt
$ ./comparaMatrizes matriz10x10_A.txt matriz10x10_B.txt 
Iguais.
$ sed -i '5,5 s/1.00/1.01/' matriz10x10_B.txt
$ ./comparaMatrizes matriz10x10_A.txt matriz10x10_B.txt 
Diferentes.
```

O comando _sed_ altera um único elemento da matriz. Fazendo novamente a comparação, vemos o programa detecta a diferença.
