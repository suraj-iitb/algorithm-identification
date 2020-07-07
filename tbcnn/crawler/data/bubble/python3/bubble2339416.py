N = int(input())
A = list(map(int,input().split()))

def BubbleSort(A, N):
 flag = 0
 sw = 0
 i = 0
 while flag == 0:
  flag = 1
  for j in range(N-1, i, -1):
   if A[j] < A[j-1]:
    A[j], A[j-1] = A[j-1], A[j]
    flag = 0
    sw += 1
  i += 1
 return str(sw)

sw = BubbleSort(A, N)
print(" ".join(map(str, A)))
print(sw)
