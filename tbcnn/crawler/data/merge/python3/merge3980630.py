n=int(input())
S=[int(i) for i in input().split()]
INF=10**10

def merge(A,l,m,r):
    cnt=0
    n1=m-l
    n2=r-m
    L,R=[0 for i in range(n1)],[0 for i in range(n2)]
    cnt=0
    L=A[l:l+n1]
    R=A[m:m+n2]
    L.append(INF)
    R.append(INF)
    i,j=0,0
    for k in range(l,r):
        cnt+=1
        if L[i]<=R[j]:
            A[k]=L[i]
            i+=1   
        else:
            A[k]=R[j]
            j+=1
    return cnt     

def mergesort(A,l,r):
    cnt=0
    if l+1<r:
        m=(l+r)//2
        cnt+=mergesort(A,l,m)
        cnt+=mergesort(A,m,r)
        cnt+=merge(A,l,m,r)
    return cnt


cnt=mergesort(S,0,n)
print(*S)
print(cnt)
