c = 0

def merge(A, l, m, r):
  global c
  L = A[l:m]
  L.append(1e10)
  R = A[m:r]
  R.append(1e10)
  i, j = 0, 0
  for k in range(l, r):
    c += 1
    if L[i] <= R[j]:
      A[k] = L[i]
      i += 1
    else:
      A[k] = R[j]
      j += 1

def sort(A, l, r):
  if r-l > 1:
    m = (l+r)//2
    sort(A, l, m)
    sort(A, m, r)
    merge(A, l, m, r)

N = int(input())
A = list(map(int, input().split()))
sort(A, 0, N)
print(" ".join(map(str, A)))
print(c)
