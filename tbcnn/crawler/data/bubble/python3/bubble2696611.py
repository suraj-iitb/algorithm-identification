# coding: UTF-8
def pprint(numlist):
  print(" ".join(map(str,numlist)))
N = int(input())
A = list(map(int,input().split()))
count = 0
flag = True
while flag:
  flag = False
  j = N - 1
  while j >= 1:
    if A[j-1] > A[j]:
      v = A[j]
      A[j] = A[j-1]
      A[j-1] = v
      flag = True
      count += 1
    j -= 1
pprint(A)
print(count)
