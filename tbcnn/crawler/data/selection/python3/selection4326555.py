def selectionSort(matrix, N):
  count = 0
  for i in range(N):
    minj = i
    for j in range(i, N):
      if A[j] < A[minj]:
        minj = j
    if A[i] != A[minj]:
      A[i], A[minj] = A[minj], A[i]
      count += 1
  return count

n = int(input())
A = list(map(int, input().split()))
count = selectionSort(A, n)
print(" ".join(map(str, A)))
print(count)

