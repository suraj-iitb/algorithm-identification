def printArray(A):
  strA = [str(i) for i in A]
  print(" ".join(strA))

def insertion(A,N):
  for i in range(1,N):
    printArray(A)
    v = A[i]
    j = i - 1
    
    while j >= 0 and A[j] > v:
      A[j+1] = A[j]
      j -= 1
    
    A[j + 1] = v
  printArray(A)
    
N = int(input())
A = list(map(int,input().split()))

insertion(A,N)
