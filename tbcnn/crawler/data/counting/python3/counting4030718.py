n = int(input())
A = [int(i) for i in input().split()]

k=max(A)

C = [0] * (k+1)

for a in A:
  C[a] = C[a] + 1

for i in range(1, k+1):
  C[i] = C[i] + C[i-1]


B = [0] * n
for a in A:
  rank = C[a]
  B[rank  - 1] = a
  C[a] = C[a] - 1

print(*B)

