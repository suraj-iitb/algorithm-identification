#coding: UTF-8
N=int(input())
L=list(map(int,input().split()))
print(' '.join(map(str,L)))
for i in range(1,N):
    v=L[i]
    j=i-1
    while j>=0 and L[j]>v:
        L[j+1]=L[j]
        j-=1
    L[j+1]=v
    print(' '.join(map(str,L)))
