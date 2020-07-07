n=int(input())
a=[int(i) for i in input().split()]

def p(a, n):
  for i in range(n):
    if i==n-1: 
      print(a[i],end='')
    else :
      print(a[i], end=' ')

def f(a, n):
  for i in range(n):
    v = a[i]
    j = i-1
    while (a[j] > v) & (j>=0):
      a[j+1] = a[j]
      j-=1
    a[j+1] = v
    p(a, n)
    print()
f(a, n)

