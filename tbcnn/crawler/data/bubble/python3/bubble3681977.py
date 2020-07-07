n=int(input())
a=list(map(int,input().split()))
cnt=0
for i in range(n):
    judge=False
    for j in range(i+1,n)[::-1]:
        if a[j-1]>a[j]:
            a[j-1],a[j]=a[j],a[j-1]
            judge=True
            cnt+=1

print(*a)
print(cnt)
