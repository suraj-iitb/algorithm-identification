n = int(input())
l = list(map(int, input().split()))
c = 0
for i in range(n):
  m = i
  for j in range(i, n):
    if l[j] < l[m]:
      m = j
  if m != i:
    l[i], l[m] = l[m], l[i]
    c += 1
print(*l)
print(c)
