N=int(input())
S=list(map(int,input().split()))

for i in range(N):
    v=S[i]
    j=i-1
    while j>=0 and S[j]>v:
        S[j+1] =S[j]
        j-=1
    S[j+1]=v
    Z=[str(a) for a in S]
    Z=" ".join(Z)
    print(Z)
