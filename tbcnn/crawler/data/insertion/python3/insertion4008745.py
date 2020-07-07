N = int(input())

A = list(map(int, input().split()))

print(" ".join(map(str, A)))

for i in range(1,N):
  v = A[i]
  for j in range(i):
    if  A[i-j-1]>v:
      A[i-j] = A[i-j-1]
      A[i-j-1] = v
    else:
      break
  print(" ".join(map(str, A)))
