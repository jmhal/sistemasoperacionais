#!/usr/bin/python
# -*- coding: utf-8 -*-

# Neste exemplo, dois processos vão atuar em uma variável compartilhada, sem exclusão mútua.

from multiprocessing import Process, Value

def soma(variavel):
   # Estou colocando um valor alto para deixar mais aparente.
   for i in range(1000):
      variavel.value = variavel.value + 1

if __name__=='__main__':
   
   # Aqui definimos a variável compartilhada.
   # Neste caso, Python exige que o tipo seja informa ("i" para inteiro)
   variavel = Value("i", 0)

   # Criando e iniciando os processos
   filho_um = Process(target = soma, args=(variavel,))
   filho_um.start()
   filho_dois = Process(target = soma, args=(variavel,))
   filho_dois.start()

   # Esperando finalizar.
   filho_um.join()
   filho_dois.join()
 
   # Valor final da variável
   print variavel.value
