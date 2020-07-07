def selection(A,n):
  count = 0
  for i in range(0,n-1):
    min = i
    for j in range(i,n):
      if(A[j] < A[min]):
        min = j
    if(min!=i):
      A[i], A[min] = A[min], A[i]
      count+=1
  printList(A)
  print(count)

def printList(A):
  print(" ".join(str(x) for x in A))

n = int(input())
A = [int(x) for x in input().split()]
selection(A,n)
