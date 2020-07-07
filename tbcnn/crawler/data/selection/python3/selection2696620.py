# coding: UTF-8
N = int(input())
A = list(map(int,input().split()))
count = 0
for i in range(N):
  j=i
  minj=i
  while j<= N-1:
    if A[j] < A[minj]:
      minj = j
    j += 1
  if i != minj:
    v=A[i]
    A[i]=A[minj]
    A[minj]=v
    count += 1
    
print(" ".join(map(str,A)))
print(count)

    

