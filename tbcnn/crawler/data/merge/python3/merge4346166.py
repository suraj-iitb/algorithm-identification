import sys
MAXINT = 1000000001

n = int(input())
S = list(map(int,input().split()))


def merge(A, l, m, r, cnt):
  n1 = m - l
  n2 = r - m
  L = [A[i] for i in range(l, l+n1)]
  R = [A[i] for i in range(m, m+n2)]
  L.append(MAXINT)
  R.append(MAXINT)
  i = 0
  j = 0
  for k in range(l,r):
    cnt += 1
    if L[i] <= R[j]:
      A[k] = L[i]
      i += 1
    else:
      A[k] = R[j]
      j += 1
  return cnt


def mergesort(A, l, r, cnt):
  if l + 1 < r:
    m = (l + r) // 2
    cnt = mergesort(A, l, m, cnt)
    cnt = mergesort(A, m, r, cnt)
    cnt = merge(A,l,m,r, cnt)
  return cnt

cnt = 0
cnt = mergesort(S, 0, n, cnt)
print(" ".join(map(str,S)))
print(cnt)


