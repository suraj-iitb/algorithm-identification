
n = int(input())
A = list(map(int, input().split()))

for i in range(n):
  v = A[i]
  j = i - 1
  while j >= 0 and A[j] >v:
    A[j + 1] = A[j]
    j -= 1

  else:
    A[j + 1] = v
    for b in range(n):
      print(A[b], end=" \n"[b + 1 == n])
