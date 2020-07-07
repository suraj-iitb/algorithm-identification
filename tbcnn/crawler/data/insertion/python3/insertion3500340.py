def inserrtionsort(l,n):
  for i in range(1,n):
    print(" ".join(l))
    v=l[i]
    j=i-1
    while int(v)<int(l[j]) and j>=0:
      l[j+1]=l[j]
      j-=1
    l[j+1]=v
  print(" ".join(l))
m=int(input())
n=list(input().split())
inserrtionsort(n,m)
