#coding: UTF-8

import sys
import math

class Algo:
  @staticmethod
  def bubbleSort(r, n):
    flag = 1
    count = 0
    while flag:
      flag = 0
      for j in range(n-1, 0, -1):
        if r[j] < r[j-1]:
          r[j], r[j-1] = r[j-1], r[j]
          count += 1
          flag = 1

    for i in range(0, n):
      if i == n-1:
        print(r[i])
      else:
        print(r[i], " ", sep="", end="")
    print(count)

N = int(input())
R= list(map(int, input().split()))
Algo.bubbleSort(R, N)
