import sys
from sys import stdin
input = stdin.readline

cnt = 0
INF = 10000000000

def merge(A, left, mid,  right):
  global cnt
  L = A[left:mid] + [INF]
  R = A[mid:right] + [INF]
  i = 0
  j = 0
  for k  in range(left , right):
    if L[i] <= R[j]:
      A[k] = L[i]
      i = i + 1
      cnt += 1
    else:
      A[k] = R[j]
      j = j + 1
      cnt += 1

def mergeSort(A, left, right):
  if left+1 < right:
    mid = (left + right)//2
    mergeSort(A, left, mid)
    mergeSort(A, mid, right)
    merge(A, left, mid, right)

n = int(input())
A =[int(x) for x in input().split()]
mergeSort(A, 0, n)

print(*A)
print(cnt)
