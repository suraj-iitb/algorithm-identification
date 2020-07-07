N = int(input())
A = list(map(int,input().split()))

def selectSort(A, N):
 sw = 0
 for i in range(N):
  minj = i
  for j in range(i, N):
   if A[j] < A[minj]:
    minj = j
  if A[i] != A[minj]:
   A[i], A[minj] = A[minj], A[i]
   sw += 1
 return str(sw)

sw = selectSort(A, N)
print(" ".join(map(str, A)))
print(sw)
