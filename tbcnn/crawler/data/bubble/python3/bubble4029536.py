n=int(input())
a=list(map(int,input().split()))
f=1
ans=0
while f==1:
  f=0
  for i in range(n-1,0,-1):
    if a[i]<a[i-1]:
      v=a[i]
      l=a[i-1]
      a[i]=l
      a[i-1]=v
      f=1
      ans+=1
print(" ".join(map(str,a)))
print(ans)

