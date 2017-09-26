#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import random
import time
from multiprocessing import Process, Array, Value, Semaphore, Lock 

def producer(buffer_, bufferSize, numberOfItems, 
             randomInterval, positions, items, nextWrite, nextRead):
   
   for step in range(numberOfItems):
      print "Producer: Starting step %d" % (step)

      print "Producer: Verifying free positions on the buffer."
      positions.acquire()

      print "Producer: Free positions available. Waiting for mutual exclusion."
      mutex.acquire()

      newItem = random.randint(0, 100)
      buffer_[nextWrite.value] = newItem
      print "Producer: New item %d on position %d." % (newItem, nextWrite.value)
      nextWrite.value = (nextWrite.value + 1) % bufferSize
      
      print "Producer: Leaving critical region."
      mutex.release()

      print "Producer: Signal available items to Consumer."
      items.release()

      interval = random.randint(0, randomInterval)
      print "Producer: Sleep for %d" % (interval)
      time.sleep(interval)

def consumer(buffer_, bufferSize, numberOfItems, 
             randomInterval, positions, items, nextWrite, nextRead):
   
   for step in range(numberOfItems):
      print "Consumer: Starting step %d" % (step)
      
      print "Consumer: Verifying items on the buffer."
      items.acquire()
      
      print "Consumer: Items available. Waiting for mutual exclusion."
      mutex.acquire()

      newItem = buffer_[nextRead.value]
      print "Consumer: New item %d from position %d." % (newItem, nextRead.value)
      nextRead.value = (nextRead.value + 1) % bufferSize

      print "Consumer: Leaving critical region."
      mutex.release()
      
      print "Consumer: Signal available positions to Producer."
      positions.release()
      
      interval = random.randint(0, randomInterval)
      print "Consumer: Sleep for %d" % (interval)
      time.sleep(interval)
  
if __name__ == "__main__":
   bufferSize = int(sys.argv[1])
   randomInterval = int(sys.argv[2])
   numberOfItems = int(sys.argv[3])
  
   print "bufferSize=%d; randomInterval=%d, numberOfItems=%d" % (bufferSize, randomInterval, numberOfItems)

   buffer_ = Array('i', bufferSize)
   nextWrite = Value('i', 0)
   nextRead = Value('i', 0) 
   mutex = Lock()
   positions = Semaphore(bufferSize)
   items = Semaphore(0)

   producer = Process(target = producer, args=(buffer_, bufferSize, 
                                               numberOfItems, randomInterval, 
					       positions, items, nextWrite, nextRead)) 
   producer.start()
   consumer = Process(target = consumer, args=(buffer_, bufferSize, 
                                               numberOfItems, randomInterval, 
					       positions, items, nextWrite, nextRead)) 
   consumer.start()
   
   producer.join()
   consumer.join()
