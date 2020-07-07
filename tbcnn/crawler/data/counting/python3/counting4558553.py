n = int(input())
A = list(map(int, input().split()))

maxlen = max(A)

C1 = [0] * (maxlen + 1)

for a in A:
  C1[a] += 1

for i in range(0, len(C1)-1):
  C1[i+1] += C1[i]

B = [0] * n
for i in range(n-1, -1, -1):
  C1[A[i]] -= 1
  B[C1[A[i]]] = A[i]

print (' '.join(map(str, B)))
