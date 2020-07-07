# -*- coding: utf-8 -*-
from sys import stdin

def insertion_sort2(A, g):
  global cnt

  for i in range(g, len(A)):
    v = A[i]
    j = i - g
    while j >= 0 and A[j] > v:
      A[j + g] = A[j]
      j = j - g
      cnt += 1
    A[j + g] = v


def shell_sort2(A, b):
  global cnt
  cnt = 0
  G = [1]
  for i in range(100):
    val = 1 + b * G[-1]
    if len(A) < val:
      break
    G.append(val)
  m = len(G)
  G.reverse()
  print(m)
  print(' '.join(map(str, G)))
  for i in range(m):
    insertion_sort2(A, G[i])
  print(cnt)
  for e in A:print(e)


n = int(stdin.readline().rstrip())
A = [int(stdin.readline().rstrip()) for i in range(n)]
shell_sort2(A, 3)

