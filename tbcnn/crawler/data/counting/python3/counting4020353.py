
n = int(input())
A = list(map(int, input().split()))

m = max(A)
B = [0] + [0] * m
result = [None] * n

for a in A:
  B[a] += 1

for i in range(1, m+1):
  B[i] += B[i-1]

for i in range(n-1, -1, -1):
  a = A[i]
  index = B[a] - 1
  result[index] = a
  B[a] -= 1
  
print(*result)
