N = int(input())
A = [int(a) for a in input().split()]

K = 10000
C = [0] * K

for i in range(N):
    C[A[i]] += 1

for i in range(1, K):
    C[i] += C[i - 1]

B = [0] * N
for i in reversed(range(N)):
    C[A[i]] -= 1
    B[C[A[i]]] = A[i]

print(*B)
