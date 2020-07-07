#! /usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

N = int(input())
A = [int(x) for x in input().split()]

if len(A) != N:
  print("[ERROR] Number of Input integer is invalid")
  sys.exit()

for i in range(N):
  v = A[i]
  j = i - 1
  while j >= 0 and A[j] > v:
    A[j + 1] = A[j]
    j -= 1
  A[j + 1] = v

  print(' '.join(map(str, A)))

