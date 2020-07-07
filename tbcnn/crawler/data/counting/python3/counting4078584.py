n = int(input())

P = list(map(int, input().split()))

Q = [0 for i in range(len(P))]

m = max(P)

def CountingSort(A, B, k):
  C = [0 for i in range(k+1)]

  for j in range(len(A)):
    C[A[j]] += 1

  for i in range(1, k+1):
    C[i] += C[i-1]

  for j in range(len(A)):
    B[C[A[j]]-1] = A[j]
    C[A[j]] -= 1

CountingSort(P, Q, m)

print(" ".join(map(str, Q)))

