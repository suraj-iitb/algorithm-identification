c=0
n=int(input())
l=list(map(int, input().split()))
for i in range(n-1):
    for j in range(n-1,i,-1):
        if l[j] < l[j-1]:
            t=l[j]
            l[j]=l[j-1]
            l[j-1]=t
            c+=1
print(*l)
print(c)
