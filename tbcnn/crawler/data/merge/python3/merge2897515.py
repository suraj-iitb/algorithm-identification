def merge(A,left,mid,right):
    n1=mid-left
    n2=right-mid
    L = A[left:mid]
    R = A[mid:right]
    L.append(float("inf"))
    R.append(float("inf"))
    """
    L=[0]*(n1+1)
    R=[0]*(n2+1)
    for i in range(n1):
        L[i]=A[left+i]
    for i in range(n2):
        R[i]=A[mid+i]
    L[n1]=float("inf")
    R[n2]=float("inf")
    """
    i=0
    j=0
    for k in range(left,right):
        global cnt
        cnt+=1
        if L[i]<=R[j]:
            A[k]=L[i]
            i=i+1
        else:
            A[k]=R[j]
            j=j+1

def mergeSort(A,left,right):
    if left+1<right:
        mid=(left+right)//2
        mergeSort(A,left,mid)
        mergeSort(A,mid,right)
        merge(A,left,mid,right)

n=int(input())
S=list(input().split())
for i in range(n):
    S[i]=int(S[i])
cnt=0
mergeSort(S,0,n)
for i in range(n):
    if i==n-1:
        print(S[i])
    else:
        print(S[i],end=" ")
print(cnt)

