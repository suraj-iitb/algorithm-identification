N = int(input())
A = list(map(int, input().split(" ")))

num_of_swp = 0
for i in range(N):
  for j in range(N - 1, i, -1):
    if A[j] < A[j - 1]:
      A[j - 1], A[j] = A[j], A[j - 1]
      num_of_swp += 1

print(" ".join(map(str, A)))
print(num_of_swp)
