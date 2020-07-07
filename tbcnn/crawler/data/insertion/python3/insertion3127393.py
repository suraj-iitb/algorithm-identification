#54
n=int(input())
*l,=list(map(int,input().split()))

for i in range(n):
    temp=l[i]
    j=i-1
    while j>=0 and l[j]>temp:
        l[j+1] = l[j]
        j-=1
    l[j+1] = temp
    print(*l)
