n = int(input())
A = list(map(int,input().split()))

def CountingSort(A,B,k):
  C = [0]*(k+1)

  for i in range(n):
    C[A[i]] += 1

  for i in range(1,k+1):
    C[i] = C[i] + C[i-1]

  for i in range(n-1,-1,-1):
    B[C[A[i]]-1 ] = A[i]
    C[A[i]] -= 1
  return B


data = [0]*(n)
data = CountingSort(A,data,max(A))

print(*data)

