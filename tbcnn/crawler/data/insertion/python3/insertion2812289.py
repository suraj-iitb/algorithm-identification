n = int(input())
a = list(map(int, input().split()))
print(*a)
for i in range(1, len(a)):
  v = a[i]
  j = i - 1
  while 0 <= j and v < a[j]:
    a[j+1] = a[j]
    j -= 1
  a[j+1] = v
  print(*a)

