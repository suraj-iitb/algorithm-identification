n=int(input())
l=list(map(int,input().split()))

c=0
for i in range(n):
    j=n-1
    while j>0:
        if l[j]<l[j-1]:
            x=l[j]
            l[j]=l[j-1]
            l[j-1]=x
            c+=1
        j-=1
        
print(" ".join(map(str,l)))
print(c)
