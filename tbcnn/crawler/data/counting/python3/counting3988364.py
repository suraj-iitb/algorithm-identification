
N = int(input())
A = list(map(int, input().split()))

VMAX = 10000

B = [0] * (N + 1)
C = [0] * (VMAX + 1)

for a in A:
    C[a] += 1

# print(C)

for i in range(1, VMAX+1):
    C[i] = C[i] + C[i-1]

# print(C)

for j in range(N):
    B[C[A[j]]] = A[j]
    C[A[j]] -= 1

print(' '.join(map(str, B[1:])))

