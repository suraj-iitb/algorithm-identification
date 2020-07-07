def insertionSort(A,n,g):
    global cnt
    for i in range(g,n):
        v=A[i]
        j=i-g
        while j>=0 and A[j]>v:
            A[j+g]=A[j]
            j-=g
            cnt+=1
        A[j+g]=v

def shellSort(A,n):
    G=[]
    k=n
    while True:
        k=max(k//2-1,1)
        G.append(k)
        if k==1:
            break
    m=len(G)
    print(m)
    for i in range(m):
        if i<m-1:
            print(G[i],end=' ')
        else:
            print(G[i])
        insertionSort(A,n,G[i])

n=int(input())
A=[]
for i in range(n):
    A.append(int(input()))

cnt=0

shellSort(A,n)

print(cnt)
for Ai in A:
    print(Ai)
