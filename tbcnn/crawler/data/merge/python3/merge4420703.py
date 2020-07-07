N=int(input())
num_list=list(map(int,input().split(" ")))
MAX=500000
L=[None]*((MAX)//2+2)
R=[None]*((MAX)//2+2)
def merge(A,left,mid,right):
    cnt=0
    n1=mid-left
    n2=right-mid


    for i in range(n1):
        L[i]=A[i+left]
    for i in range(n2):
        R[i]=A[i+mid]
    L[n1]=(10**9+1)
    R[n2]=(10**9+1)
    j,k=0,0
    for i in range(left,right):
        cnt+=1
        if L[j]<=R[k]:
            A[i]=L[j]
            j+=1
        else:
            A[i]=R[k]
            k+=1
    return cnt
def mergesort(A,left,right):
    if left+1<right:
        mid=(left+right)//2
        cntL=mergesort(A,left,mid)
        cntR=mergesort(A,mid,right)
        return merge(A,left,mid,right)+cntL+cntR
    return 0
cnt=mergesort(num_list,0,N)
print(*num_list)
print(cnt)
