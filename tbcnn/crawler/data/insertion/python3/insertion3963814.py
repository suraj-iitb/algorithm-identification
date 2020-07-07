n=int(input())
l=list(map(int, input().split()))
for i in range(n):
    if i!=n:
        part_l=sorted(l[0:i+1])  
        l=part_l+l[i+1:n+1]
        print(*l)

    elif i==n:
        if l[i-1]>l[i]:
            l=+list(reversed(l[i-1:i]))
            print(*l)
