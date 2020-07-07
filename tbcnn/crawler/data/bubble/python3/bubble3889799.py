n = int(input())
a = list(map(int, input().split()))

ans = 0

flag = True
while flag:
  flag = False
  for i in range(1, n):
    if a[i] < a[i-1]:
      a[i], a[i-1] = a[i-1], a[i]
      ans += 1
      flag = True

print(" ".join(map(str, a)))
print(ans)
