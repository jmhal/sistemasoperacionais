# Trabalho de Sistemas Operacionais

Este documento descreve o Trabalho da Disciplina de Sistemas Operacionas 2017.2, do curso de Bacharelado em Ciências da Computação do
campus da UFC em Quixadá.

## Objetivos

O objetivo do trabalho é exercitar os conceitos apresentados na disciplina de Sistemas Operacionais. Em detalhes, vamos trabalhar com o conceito de _threads_ e na interface de acesso ao _sistema de arquivos_. 

## Descrição do Problema

O trabalho consiste em implementar a **multiplicação de matrizes**. Considere duas matrizes A(mxp) e B(pxn), ou seja, matriz A tem _m_ linhas por _p_ colunas enquanto matriz B tem _p_ linhas por _n_ colunas. A multiplicação de matrizes consiste na definição da matriz C(mxn), na qual cada elemento _c(i,j)_ corresponde ao somatório de _k=1_ até _k=p_ dos termos _a(i,k)_ * _b(k,j)_. Um algoritmo para tal operação pode ser visto como:

```
programa multiplica_matrizes;
   matriz A, B, C;
   inteiro linha, coluna, i, acumula;
   ler A;
   let B;
   se A.colunas != B.linhas então
      imprima "Entrada Inválida!!!"
      retorna ERRO;
   para linha de 1 até A.linhas faça
     para coluna de 1 até B.colunas faça
       acumula = 0;
       para k de 1 até A.colunas faça
         acumula = acumula + A[linha][k]*B[k][coluna];
       fimpara;
       C[linha][coluna]=acumula;
     fimpara;
   fimpara;
   imprima C;
fim programa;
```

Observem que a parte mais complexa do algoritmo são os três laços aninhados. Para aumentar sua compreensão do problema, execute manualmente uma multiplicação com matrizes de pequena ordem, como 3x3 ou 4x4. 


## Ambiente de Desenvolvimento

O ambiente para desenvolvimento e execução do projeto deve ser o sistema operacional *Linux*. Aqueles que não se sentirem a vontade para instalar o Linux podem utilizar o [VirtualBox](www.virtualbox.org) ou qualquer computador dos laboratórios do campus. Poderá ser feito e *qualquer linguagem*.

Você deve criar na sua conta do _BitBucket_ um repositório chamado **trabalhoso** para armazenar todo código e documentação produzido. Esse repositório deve ser privado, sendo que você deve convidar o professor como membro (usuário: jmhal, e-mail: joao.marcelo@ufc.br).

## Atividades

Você deve realizar cada uma das atividades abaixo para completar o trabalho. 

1.  Versão Serial

A primeira etapa consistem em implementar a versão serial da multiplicação de matrizes. Seu programa serial, sem utilização de _threads_, deve receber como parâmetro dois arquivos de texto, cada um contendo uma matriz. Em seguida, deve realizar a multiplicação das matrizes e guardar o resultado em um arquivo cujo o nome é informado no terceiro parâmetro. Por exemplo, considerando a execução no terminal do Linux: 

```
$./multiplicaMatrizesSerial A.txt B.txt C.txt
Calculando o produto de Matrizes...
Matriz Resultante salva em C.txt
```

O formato do arquivo de texto que armazena as matrizes seguem um padrão pré-definido. Por simplicidade, vamos considerar apenas matrizes quadradas, nas quais o número de colunas é igual ao número de linhas. A primeira linha do arquivo de texto tem apenas um número, que é justamente a ordem da matriz. Em seguida, cada linha da matriz é representada com os elementos separados pelo símbolo **:**. Por exemplo, um arquivo com o seguinte conteúdo:

```
3
1.0:2.0:3.0
4.0:5.0:6.0
7.0:8.0:9.0
```
representa uma matriz 3 x 3 com a(1,1) = 1.0, a(1,2) = 2.0, a(1,3) = 3.0, a(2,1) = 4.0, a(2,2) = 5.0, a(2,3)= 6.0, a(3,1) = 4.0, a(3,2) = 5.0, a(3,3)= 6.0. Considere como outro exemplo um arquivo chamado _matriz10x10.txt_:

```
10
1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0
1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0
1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0
1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0
1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0
1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0
1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0
1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0
1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0
1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0
1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0:1.0
```

A execução:

```
$./multiplicaMatrizesSerial matriz10x10.txt matriz10x10.txt matrizResultado.txt
Calculando o produto de Matrizes...
Matriz Resultante salva em matrizResultado.txt
```

Vai gerar um arquivo _matrizResultado.txt_:

```
10
10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0
10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0
10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0
10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0
10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0
10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0
10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0
10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0
10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0
10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0
10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0:10.0
```

Vocês devem considerar a matriz como elementos _ponto flutuante_. Nos exemplos, estou considerando a linguagem em C, mas nada impede que vocês usem Java ou Python:

```
$ java MultiplicaMatrizesSerial matriz10x10.txt matriz10x10.txt matrizResultado.txt
Calculando o produto de Matrizes...
Matriz Resultante salva em matrizResultado.txt
$ python MultiplicaMatrizesSerial.py matriz10x10.txt matriz10x10.txt matrizResultado.txt
Calculando o produto de Matrizes...
Matriz Resultante salva em matrizResultado.txt

```

Podem utilizar ambientes como _Eclipse_ ou _CodeBlocks_, mas aprendam a executar o código pelo terminal. A pasta **matriz** deste repositório contém programas auxiliares que podem ajudar vocês a testarem seus programas.

2.  Versão Paralela

A segunda etapa consiste em criar uma versão paralela que utilize _threads_ para dividir a carga de trabalho da versão serial. Como distribuir o trabalho fica a seu critério, mas seu programa paralelo só deve criar um número de _threads_ igual ao número de núcleos de processamento presente na máquina que executa o código. Por exemplo, ao executar em uma máquina _dual core_, dois _threads_ devem ser criados. 

3.  Análise de Desempenho

A terceira etapa consiste em preencher a tabela abaixo:

Ordem da Matriz | Tempo Serial | Tempo Paralelo
----------------|--------------| --------------
1000            |              |
2000            |              |
3000            |              | 
4000            |              | 
5000            |              |

Para matrizes nas ordens de 1000 até 5000, execute tanto a versão serial quanto a versão paralela do programa. Você pode, para facilitar, considerar matrizes com todos elementos iguais a **1.0**. Para esses valores, é esperado que a execução demore bastante, mas deve ficar menos de uma hora mesmo para matrizes 5000x5000. Para medir o tempo, você deve usar o comando _time_ do Linux:

```
$ time ./multiplicaMatrizesSerial matriz1000x1000.txt matriz1000x1000.txt matrizResultado.txt
Calculando o produto de Matrizes...
Matriz Resultante salva em matrizResultado.txt
real	0m33,690s
user	0m33,445s
sys	0m0,057s

```

Ao colocar o comando _time_ antes de qualquer comando do Linux, o sistema irá registrar o tempo de execução. O valor _user_ equivale a quanto tempo foi gasto executando em espaço de usuário. O campo _sys_ informa quanto tempo foi executado do sistema operacional para atender as chamadas de sistema do processo. Já o valor _real_ é o que você deve colocar na tabela, pois equivale a diferença de tempo entre o final e início da execução. Em outras palavras, _real_ é o tempo que o usuário percebe como duração da execução.

4.  Documentação

Além do código fonte da versão serial e paralela, você deve criar um arquivo **README.md** descrevendo em detalhes:

+ Configuração da máquina na qual foi feita a análise:
    * Processador
    * Memória
    * Versão do Sistema Operacional 
    * Versão dos compiladores/máquinas virtuais
+ Passo-a-passo para instalação:
    * Pacotes a serem instalados 
    * Etapas para compilação de cada versão, serial e paralela.

O código pode ser organizado da forma que acharem melhor.

## Entrega

O prazo de entrega é dia **01/12/2017**. A apresentação individual será combinada com cada aluno que entregar o trabalho. 

## Avaliação

O trabalho terá valor de 10,0 (dez) pontos. O trabalho é **INDIVIDUAL**. A divisão dos pontos será da seguinte forma:

+ **O código funciona?** (Avaliação Objetiva)
    * Se o código funcionar e atender os requisitos solicitados, o aluno garantirá 5,0 (cinco) pontos.
    * Tanto a versão paralela quanto serial devem funcionar.
+ **Apresentação Individual** (Avaliação Subjetiva)
    * O aluno terá que explicar ao professor o código entregue, em um momento a ser definido. 
    * De acordo com a apresentação, o aluno poderá garantir até mais 5,0 (cinco) pontos.

Dúvidas: entrem contato comigo por e-mail (joao.marcelo@ufc.br), pelo Slack da disciplina ou na sala de aula.
