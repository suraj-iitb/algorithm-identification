n=int(input());a=list(map(int,input().split()));c=0
for i in range(n):
 for j in range(i+1,n)[::-1]:
  if a[j]<a[j-1]:
   a[j],a[j-1]=a[j-1],a[j];c+=1
print(*a)
print(c)
