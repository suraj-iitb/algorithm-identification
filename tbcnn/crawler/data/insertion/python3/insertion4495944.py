n = int(input())
l = list(map(int, input().split()))
print(*l)
for i in range(1,n):
    v=l[i]
    j=i-1
    while j>=0 and v<l[j]:
        l[j+1]=l[j]
        j-=1
    l[j+1]=v
    print(*l)
        

