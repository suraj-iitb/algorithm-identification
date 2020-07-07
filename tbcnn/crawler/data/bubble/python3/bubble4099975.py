n=int(input())
a=[int(i) for i in input().split()]

def bs(a, n):
  cnt=0
  f = True
  while f:
    f = False
    for i in range(n-1):
      v = a[i]
      if v>a[i+1]:
        a[i] = a[i+1]
        a[i+1] = v
        cnt+=1
        f = True
  return a,cnt

b,c = bs(a, n)

for i in range(n):
    if i==n-1:
      print(b[i], end='')
    else:
      print(b[i], end=' ')

print()
print(c)
