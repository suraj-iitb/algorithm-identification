def countint_sort(A, k):
  B = [0] * (len(A))
  C = [0] * (k + 1)
  for j in range(len(A)):
    C[A[j]] += 1
  for i in range(1, k + 1):
    C[i] = C[i] + C[i - 1]
  for j in range(len(A)):
    ib = C[A[j]] - 1
    B[ib] = A[j]
    C[A[j]] -= 1
  return B

n = int(input())
A = list(map(int, input().split()))
print(" ".join(map(str, countint_sort(A, max(A)))))
