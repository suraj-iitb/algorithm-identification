#! /usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

N = int(input())
A = [int(x) for x in input().split()]

if len(A) != N:
  print("[ERROR] Number of Input integers is invalid")
  sys.exit()

swap_count = 0

for i in range(N):
  for j in range(N - 1, i, -1):
    if A[j] < A[j - 1]:
      A[j], A[j - 1] = A[j - 1], A[j]
      swap_count += 1

print(' '.join(map(str, A)))
print(swap_count)

