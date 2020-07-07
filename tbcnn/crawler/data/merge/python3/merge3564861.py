n = int(input())
a = list(map(int, input().split()))
INF = 1000000000
count = 0
def merge(A, left, mid, right):
  L = A[left:mid] + [INF]
  R = A[mid:right] + [INF]
  global count
  i, j = 0, 0
  for k in range(left, right):
    if L[i] <= R[j]:
      A[k] = L[i]
      i += 1
      count += 1
    else:
      A[k] = R[j]
      j += 1
      count += 1

def mergeSort(A, left, right):
  if left + 1 < right:
    mid = int((left+right)/2)
    mergeSort(A, left, mid)
    mergeSort(A, mid, right)
    merge(A, left, mid, right)
  return

mergeSort(a, 0, n)
print(*a)
print(count)
