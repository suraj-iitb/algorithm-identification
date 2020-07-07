N = int(input())
A = list(map(int, input().split()))

def printa(A):
  for i in range(N - 1):
    print(A[i] ,end=' ')
  print(A[N - 1],)
  
printa(A)
for i in range(1, N):
  v = A[i]
  j = i - 1
  while j >= 0 and A[j] > v:
    A[j+1] = A[j]
    j -= 1
  A[j+1] = v
  printa(A)
