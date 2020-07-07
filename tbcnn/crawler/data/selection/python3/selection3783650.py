n = int(input())
a = list(map(int, input().split()))
b = []
flag = 0
m = 0

for i in range(n):
    x = a.index(min(a))
    if a[0] > a[x]:
      a[0], a[x] = a[x], a[0]
      flag = flag + 1
    b.append(a[0]) 
    del a[0]
      
for k in range(n):
    print(b[k], end="")
    if k == n-1:
        print("")
    else:
        print(" ", end="")
print(flag)
