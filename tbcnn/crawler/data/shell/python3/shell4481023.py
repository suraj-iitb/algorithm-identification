def insertionSort(A,n,g,cnt):
    for i in range(g,n):
        v = A[i]
        j = i-g
        while (j>=0)*(A[j]>v):
            A[j+g]=A[j]
            j = j-g
            cnt[0] += 1
        A[j+g] = v
A =[]
N = int(input())
for i in range(N):
    A.append(int(input()))
cnt = [0]
import math
m = math.floor(math.log(N,2))+1
G = [math.ceil(N/2)]
for i in range(1,m-1):
    G.append(math.ceil(G[i-1]/2))
G.append(N-sum(G))
if G[len(G)-1] != 1:
    G[len(G)-1] = 1
for k in range(m):
    insertionSort(A,N,G[k],cnt)
print(m)
for i in range(m):
    print(f"{G[i]}",end=" ")
print(f"\n{cnt[0]}")
for i in range(N):
    print(f"{A[i]}")
