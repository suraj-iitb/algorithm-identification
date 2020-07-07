def insertion(A,n):
  for i in range(0,n):
    tmp = A[i]
    j = i - 1
    while(A[j] > tmp and j >= 0):
      A[j+1] = A[j]
      j-=1
    A[j+1] = tmp
    printList(A)


def printList(A):
  print(" ".join(str(x) for x in A))

n = int(input())
A = [int(x) for x in input().split()]
insertion(A,n)
