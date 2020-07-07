n=int(input())
ls=list(map(int,input().split()))

print(*ls)
for i in range(1,n):
    v=ls[i]
    j=i-1
    while j>=0 and ls[j]>v:
        ls[j+1]=ls[j]
        j-=1
    ls[j+1]=v
    print(*ls)

