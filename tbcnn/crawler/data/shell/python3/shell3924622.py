import sys
input = sys.stdin.readline
import math

N=int(input())
B = [int(input()) for _ in range(N)]

def insertionSort(A,n,g,cnt):
    for i in range(g,n):
        v=A[i]
        j=i-g
        while j>=0 and A[j]>v:
            A[j+g]=A[j]
            j=j-g
            cnt+=1
        A[j+g]=v
    
    return cnt

def shellSort(A,n):
    cnt=0
    G = []
    tmp=n//2
    while tmp:
        G.append(tmp)
        tmp=tmp//2
    
    if len(G)==0:
        G.append(1)
    m=len(G)
    print(m)
    print(*G)
    for i in range(m):
        cnt=insertionSort(A,n,G[i],cnt)
    print(cnt)
    
    for x in A:
        print(x)
    
shellSort(B,N)

