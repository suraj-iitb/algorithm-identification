#coding: UTF-8

import sys

class Algo:
  @staticmethod
  def insersion_sort(A, N):
    for i in range(1, N):
      for k in A:
        if k==A[len(A)-1]:
          print(k)
        else:
          print(k, " ", sep="", end="")
      v = A[i]
      j = i-1
      while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
      A[j+1] = v
    for k in A:
      if k==A[len(A)-1]:
        print(k)
      else:
        print(k, " ", sep="", end="")

N = int(input())
A = list(map(int, input().split()))
Algo.insersion_sort(A, N)
