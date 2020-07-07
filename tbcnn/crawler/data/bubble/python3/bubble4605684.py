N = int(input())
A = list(map(int, input().split()))

ans = 0
for i in range(0, len(A)-1):
  for j in range(len(A)-2, i-1, -1):
    if A[j] > A[j+1]:
      A[j], A[j+1] = A[j+1], A[j]
      ans += 1

print(" ".join(list(map(str, A))))
print(ans)
