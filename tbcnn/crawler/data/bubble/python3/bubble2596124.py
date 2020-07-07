N = int(input())
a = list(map(int, input().split()))
flag = 1
z = 0
while flag:
  flag = 0
  for j in range(N - 1, 0, -1):
    if a[j] < a[j - 1]:
      a[j - 1], a[j] = a[j], a[j - 1]
      flag = 1
      z += 1
print(*a)
print(z)
