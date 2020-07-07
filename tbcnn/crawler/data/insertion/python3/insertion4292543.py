N = int(input())
A = list(map(int, input().split()))

for i in range(N):
  p = i -1
  while p >= 0 and A[p] > A[p+1]:
    A[p], A[p+1] = A[p+1], A[p]
    p -= 1
  print(*A)
