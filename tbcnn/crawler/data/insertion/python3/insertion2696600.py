# coding: UTF-8
def pprint(numlist):
  print(" ".join(map(str,numlist)))
N = int(input())
A = list(map(int, input().split()))
pprint(A)
for i in range(1,N):
  j = i
  v = A[i]
  while A[j] < A[j-1] and j >= 1:
    A[j] = A[j-1]
    A[j-1] = v
    j -= 1
  pprint(A)
  

