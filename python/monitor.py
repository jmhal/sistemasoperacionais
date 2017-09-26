#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import random
import time
from multiprocessing import Process, Array, Value, Condition, Lock 

SIZE = 3 
STEPS = 5

class Monitor:
   def __init__(self, bufferSize):
      # Shared Data
      self.buffer = Array('i', bufferSize)
      self.bufferSize = bufferSize
      self.freePositions = Value('i', bufferSize)
      
      # Local Data
      self.nextRead = 0
      self.nextWrite = 0
      
      # Control Data
      self.mutex = Lock()
      self.items = Condition(self.mutex)
      self.positions = Condition(self.mutex)

   def produce(self, value):
      self.mutex.acquire()
      if (self.freePositions.value == 0):
         self.positions.wait()
      
      self.buffer[self.nextWrite] = value
      self.nextWrite = (self.nextWrite + 1) % self.bufferSize
      self.freePositions.value = self.freePositions.value - 1
      
      self.items.notify()
      self.mutex.release()

   def consume(self):
      newItem = None
      self.mutex.acquire()
      if (self.freePositions.value == self.bufferSize):
         self.items.wait()
      
      newItem = self.buffer[self.nextRead]
      self.nextRead = (self.nextRead + 1) % self.bufferSize
      self.freePositions.value = self.freePositions.value + 1

      self.positions.notify()
      self.mutex.release()
      return newItem

def producer(m):
   for i in range(STEPS):
      newItem = random.randint(0, 100)
      m.produce(newItem)
      print "Producer: step %d item %d" % (i, newItem)

def consumer(m):
   for i in range(STEPS):
      newItem = m.consume()
      print "Consumer: step %d item %d" % (i, newItem)

if __name__ == "__main__":
   monitor = Monitor(SIZE)

   p1 = Process(target = producer, args=(monitor,)) 
   p1.start()

   p2 = Process(target = consumer, args=(monitor,)) 
   p2.start()
   
   p1.join()
   p2.join()

