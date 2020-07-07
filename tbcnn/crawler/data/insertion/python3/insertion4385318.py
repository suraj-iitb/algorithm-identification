N=int(input())
R=list(map(int,input().split()))

print(*R)

for n in range(1,N):
    if R[n-1]<=R[n]:
        pass
    elif R[n-1]>R[n]:
        v=R[n]
        for i in R[:n]:
            if i>v:
                j=R.index(i)
                break
        R[j+1:n+1]=R[j:n]
        R[j]=v
    print(*R)
