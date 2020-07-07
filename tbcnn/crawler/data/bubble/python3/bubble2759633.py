n = int(input())
l = list(map(int, input().split()))
f = 1; c = 0
while f > 0:
  f = 0
  for j in range(n-1, 0, -1):
    if l[j] < l[j-1]:
      l[j], l[j-1] = l[j-1], l[j]
      f = 1; c += 1
print(*l)
print(c)
