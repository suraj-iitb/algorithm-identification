N = int(input())
A = list(map(int, input().split()))
r = 0

for i in range(N-1):
  flag = False
  for j in range(N-2, i-1, -1):
    if A[j] > A[j+1]:
      t = A[j]
      A[j] = A[j+1]
      A[j+1] = t
      flag = True
      r += 1

print(" ".join(map(str, A)))
print(r)
