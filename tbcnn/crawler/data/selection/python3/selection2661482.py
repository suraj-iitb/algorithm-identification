#coding: UTF-8

import sys
import math

class Algo:
  @staticmethod
  def insertionSort(r, n):
    count = 0
    for i in range(0,n):
      minj = i
      for j in range(i,n):
        if r[j] < r[minj]:
          minj = j
      if r[i] != r[minj]:
        r[i], r[minj] = r[minj], r[i]
        count += 1
    
    for i in range(0,n):
      if i == n-1:
        print(r[i])
      else:
        print(r[i], " ", sep="", end="")
    print(count)

N = int(input())
R= list(map(int, input().split()))
Algo.insertionSort(R, N)
