n=int(input())
da=list(map(int,input().split()))
chco=0
for i in range(n):
    minj=i
    for j in range(i,n):
        if da[j]<da[minj]:
            minj=j
    if i!=minj:
        x=da[i]
        da[i]=da[minj]
        da[minj]=x
        chco+=1
for i in range(n):
    if i==n-1:
        print(da[i])
    else:
        print(da[i],end=' ')
print(chco)
