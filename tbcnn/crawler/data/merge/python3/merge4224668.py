INFTY=1000000000

n=int(input())
A=list(map(int,input().split()))

def merge(A,left,mid,right):
    cnt=0
    n1=mid-left
    n2=right-mid
    L=[A[left+i] for i in range(n1)]
    R=[A[mid+i] for i in range(n2)]
    L.append(INFTY)
    R.append(INFTY)
    i=0
    j=0
    for k in range(left,right):
        cnt+=1
        if L[i]<=R[j]:
            A[k]=L[i]
            i+=1
        else:
            A[k]=R[j]
            j+=1
    return cnt

def mergeSort(A,left,right):
    if left+1<right:
        mid=(left+right)//2
        cnt1=mergeSort(A,left,mid)
        cnt2=mergeSort(A,mid,right)
        return merge(A,left,mid,right)+cnt1+cnt2
    return 0

cnt=mergeSort(A,0,n)
print(' '.join(map(str,A)))
print(cnt)
