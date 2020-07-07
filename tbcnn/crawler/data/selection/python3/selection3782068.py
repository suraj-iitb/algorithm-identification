N = int(input())
A = list(map(int, input().split()))

cnt = 0
for i in range(N):
  min_x = i
  for j in range(i, N):
    if A[j] < A[min_x]:
      min_x = j
  if (i != min_x):
    A[i], A[min_x] = A[min_x], A[i]
    cnt += 1

print(" ".join(map(str, A)))
print(cnt)
