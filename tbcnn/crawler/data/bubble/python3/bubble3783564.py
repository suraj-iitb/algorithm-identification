n = int(input())
a = list(map(int, input().split()))
flag = 0
for i in range(n):
  for j in range(1,n):
    if a[j] < a[j-1]:
      a[j], a[j-1] = a[j-1], a[j]
      flag = flag + 1
for i in range(n):
    print(a[i], end="")
    if i == n-1:
        print("")
    else:
        print(" ", end="")
print(flag)
