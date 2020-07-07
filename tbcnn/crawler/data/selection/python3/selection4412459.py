N = int(input())
A = list(map(int,input().split()))

swapcnt = 0

def bubbleSort(A):
  global N,swapcnt
  for i in range(N):
    for j in  range(N-1,i,-1):
      if A[j] < A[j-1]:
        x = A[j]
        A[j] = A[j-1]
        A[j-1] = x
        swapcnt += 1

def selectionSort(A):
  global N,swapcnt
  for i in range(N):
    minj = i
    for j in range(i,N):
      if A[j] < A[minj]:
        minj = j
    if minj != i :
      x = A[minj]
      A[minj] = A[i]
      A[i] = x
      swapcnt += 1

#bubbleSort(A)
selectionSort(A)
strA = [str(a) for a in A]
print(" ".join(strA))
print(swapcnt)
