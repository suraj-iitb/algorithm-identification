n = int(input())
a = list(map(int, input().split()))
cnt = 0
for i in range(n):
  for j in range(1, n-i):
    if a[n-j] < a[n-j-1]:
      cnt += 1
      a[n-j], a[n-j-1] = a[n-j-1], a[n-j]
print(" ".join([str(i) for i in a]))
print(cnt)
