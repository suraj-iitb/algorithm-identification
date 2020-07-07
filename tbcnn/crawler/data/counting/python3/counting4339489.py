def CountingSort(A, B, k):
  C = [0 for i in range(k + 1)]

  for j in range(0, n):
    C[A[j]] += 1

  for i in range(1, k + 1):
    C[i] = C[i] + C[i - 1]

  for j in reversed(range(0, n)):
    B[C[A[j]]] = A[j]
    C[A[j]] -= 1

n = int(input())
A = list(map(int, input().split()))
B = [0 for _ in range(n + 1)]

CountingSort(A, B, max(A))
print(*B[1:])

