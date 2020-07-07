N=int(input())
L=list(map(int,input().split()))

print(' '.join(map(str,L)))
for i in range(1,N):
    for j in range(i):
        if L[i] < L[j]:
            v=L.pop(i)
            L.insert(j,v)
            
    print(' '.join(map(str,L)))
