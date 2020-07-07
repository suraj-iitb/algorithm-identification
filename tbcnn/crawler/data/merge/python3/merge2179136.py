def merge(A, l, m, r):
  L = A[l:m] + [SENTINEL]
  R = A[m:r] + [SENTINEL]

  i = 0
  j = 0
  for k in range(l, r):
    if L[i] <= R[j]:
      A[k] = L[i]
      i += 1
    else:
      A[k] = R[j]
      j += 1
  global count
  count += r - l

def merge_sort(A, l, r):
  if l + 1 < r:
    m = (l + r) // 2
    merge_sort(A, l, m)
    merge_sort(A, m, r)
    merge(A, l, m, r)

SENTINEL = float('inf')
n = int(input())
A = list(map(int, input().split()))
count = 0
merge_sort(A, 0, len(A))
print(" ".join(map(str, A)))
print(count)
