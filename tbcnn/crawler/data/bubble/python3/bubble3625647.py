n=int(input())
da=list(map(int,input().split()))
chco=0
flag=1
while flag:
    flag=0
    for i in range(n-1,0,-1):
        if da[i]<da[i-1]:
            da[i],da[i-1]=da[i-1],da[i]
            flag=1
            chco+=1
for i in range(n):
    if i==n-1:
        print(da[i])
    else:
        print(da[i],end=' ')
print(chco)
