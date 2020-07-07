n=int(input())
lst=list(map(int,input().split()))
for i in range(n):
    x=lst[i]
    for j in range(i)[::-1]:
        if lst[j]<x:break
        lst[j+1]=lst[j]
        lst[j]=x
    print(*lst)
