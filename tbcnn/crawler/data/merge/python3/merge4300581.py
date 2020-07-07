n = int(input())
S = list(map(int, input().split(' ')))
count = 0

def merge(A, left, mid, right):
  global count
  n1 = mid - left
  n2 = right - mid
  L = A[left:left+n1]
  R = A[mid:mid+n2]
  L.append(10**9+1)
  R.append(10**9+1)
  i, j = 0, 0
  for k in range(left, right):
    count += 1
    if L[i] <= R[j]:
      A[k] = L[i]
      i += 1
    else:
      A[k] = R[j]
      j += 1

def mergeSort(A, left, right):
  if left + 1 < right:
    mid = (left + right) // 2
    mergeSort(A, left, mid)
    mergeSort(A, mid, right)
    merge(A, left, mid, right)

mergeSort(S, 0, n)

print(*S)
print(count)
