count = 0 
INFTY = 10 ** 10

def merge(A, left, mid, right):
  global count
  n1 = mid - left;
  n2 = right - mid;

  L = []
  R = []

  L = A[left:left+n1]
  R = A[mid:mid+n2]

  L.append(INFTY)
  R.append(INFTY)

  i = 0
  j = 0
  for k in range(left, right):
    count = count + 1
    if L[i] <= R[j]:
      A[k] = L[i]
      i = i + 1
    else:
      A[k] = R[j]
      j = j + 1

def mergeSort(A, left, right):
  if left+1 < right:
    mid = int((left + right)/2);
    mergeSort(A, left, mid)
    mergeSort(A, mid, right)
    merge(A, left, mid, right)

import sys

n = sys.stdin.readline()
for line in sys.stdin:
  items = line.strip().split()
  items = [ int(x) for x in items ]
  mergeSort(items, 0, len(items))
  print(" ".join(map(str, items)))
  print(count)
