#!/usr/bin/python3
import sys

def read_matrix(filename):
   matrix_file = open(filename, "+r")
   order = int(matrix_file.readline())
   values = [ [ float(a) for a in line.split(':') ] for line in matrix_file.readlines() ] 
   return (order, values)

def save_matrix(matrix, order, filename):
   matrix_file = open(filename, "+w")
   matrix_file.write("%d\n" % order)
   for line in matrix:
      for element in line:
         matrix_file.write("%.3f:" % element)
      matrix_file.seek(matrix_file.tell() - 1)
      matrix_file.write("\n")
   matrix_file.close()

if __name__ == "__main__":

   matrix_A_filename = sys.argv[1]
   matrix_B_filename = sys.argv[2]
   matrix_C_filename = sys.argv[3]

   order_A, matrix_A = read_matrix(matrix_A_filename)
   order_B, matrix_B = read_matrix(matrix_B_filename)

   matrix_C = [ [ 0.0 for i in range(order_A) ] for j in range(order_A) ]

   for i in range(order_A):
      for j in range(order_A):
         for k in range(order_A):
            matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j]

   save_matrix(matrix_C, order_A, matrix_C_filename)
