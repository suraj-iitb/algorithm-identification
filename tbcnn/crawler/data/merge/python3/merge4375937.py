import math

n = int(input())
A = list(map(int,input().split()))
count = 0

def merge(A, left, mid, right):

  global  count

  L = A[left:mid]
  L.append(math.inf)
  R = A[mid:right]
  R.append(math.inf)
  i = 0
  j = 0
  for k in range(left,right):
    count += 1
    if L[i] <= R[j]:
      A[k] = L[i]
      i = i + 1
    else:
      A[k] = R[j]
      j = j + 1


def mergeSort(A,left,right):
    if left +1 < right:
        mid = (left+right) // 2
        mergeSort(A,left,mid)
        mergeSort(A,mid,right)
        merge(A,left,mid,right)


mergeSort(A,0,n)
x = list(map(str,A))
print(" ".join(x))
print(count)
