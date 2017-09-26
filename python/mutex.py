#!/usr/bin/python
# -*- coding: utf-8 -*-

# Neste exemplo, dois processos vão atuar em uma variável compartilhada

from multiprocessing import Process, Value, Lock

# Defino um mutex para controlar o acesso
mutex = Lock()

def soma(variavel):
   # Estou colocando um valor alto para deixar mais aparente.
   for i in range(1000):
      # operação down no mutex
      mutex.acquire()

      # região crítica
      variavel.value = variavel.value + 1

      # operação up no mutex
      mutex.release()

if __name__=='__main__':
   
   # Aqui definimos a variável compartilhada.
   # Neste caso, Python exige que o tipo seja informa ("i" para inteiro)
   variavel = Value("i", 0)

   # Criando e iniciando os processos, passando o mutex como parâmetro
   filho_um = Process(target = soma, args=(variavel,))
   filho_um.start()
   filho_dois = Process(target = soma, args=(variavel,))
   filho_dois.start()

   # Esperando finalizar.
   filho_um.join()
   filho_dois.join()
 
   # Valor final da variável
   print variavel.value
