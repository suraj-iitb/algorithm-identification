N=int(input())
L=list(map(int,input().split()))

n=0
for i in range(N):
    for j in range(N-1,i,-1):
        v=L[j]
        u=L[j-1]
        
        if v < u:
            L[j]=u
            L[j-1]=v
            n+=1
            
print(' '.join(map(str,L)))
print(n)
