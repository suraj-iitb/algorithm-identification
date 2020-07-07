inf=float("inf")
def merge(a,left,mid,right):
    count=0
    n1=mid-left
    n2=right-mid
    L=[0]*(n1+1)
    R=[0]*(n2+1)
    for i in range(n1):
        L[i]=a[left+i]
    for i in range(n2):
        R[i]=a[mid+i]
    L[n1]=inf
    R[n2]=inf
    i=0
    j=0
    for k in range(left,right):
        count+=1
        if L[i]<=R[j]:
            a[k]=L[i]
            i+=1
        else:
            a[k]=R[j]
            j+=1
    return count

def mergeSort(a,left,right):
    if left+1<right:
        mid=(left+right)//2
        return mergeSort(a,left,mid)+mergeSort(a,mid,right)+merge(a,left,mid,right)
    return 0
n=int(input())
*a,=map(int,input().split())
ans=mergeSort(a,0,n)
print(*a)
print(ans)

