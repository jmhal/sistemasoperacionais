#!/usr/bin/python
# -*- coding: utf-8 -*-
import time
from multiprocessing import Process

# Exemplo mostrando a criação de processos

def mensagem(id, texto):
   print "Processo " + str(id) + ": " + texto  
   while True :
      print "Processo " + str(id)
      time.sleep(5)

if __name__=='__main__':
   print "Processo Pai: Olá"

   print "Processo Pai: Criando dois processos."
   filho_um = Process(target = mensagem, args=(1, "Olá."))
   filho_um.start()
   filho_dois = Process(target = mensagem, args=(2, "Olá."))
   filho_dois.start()
   print "Processo Pai: Processos criados."

   filho_um.join()
   filho_dois.join()
 
