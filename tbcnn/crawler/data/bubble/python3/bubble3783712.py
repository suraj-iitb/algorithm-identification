N = int(input())
A = list(map(int, input().split()))

cnt = 0
flag = True
while flag:
  flag = False
  for i in reversed(range(1, N)):
    if A[i] < A[i-1]:
      A[i], A[i-1] = A[i-1], A[i]
      flag = True
      cnt += 1

print(" ".join(map(str, A)))
print(cnt)
