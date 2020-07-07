n = int(input())

S = list(map(int, input().split()))

c = 0

def merge(A, left, mid, right):
  inf = float('inf')
  L = A[left:mid] + [inf]
  R = A[mid:right] + [inf]
  i = 0
  j = 0
  global c
  for k in range(left, right):
    if L[i] <= R[j]:
      A[k] = L[i]
      i += 1
      c += 1
    else:
      A[k] = R[j]
      j += 1
      c += 1

def mergesort(A, left, right):
  if left+1 < right:
    mid = (left + right)//2
    mergesort(A, left, mid)
    mergesort(A, mid, right)    
    merge(A, left, mid, right)

mergesort(S, 0, n)

print(" ".join(map(str, S)))

print(c)
