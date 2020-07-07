def merge(A,left,mid,right):
    L=A[left:mid]+[float("INF")]
    R=A[mid:right+1]+[float("INF")]
    i=0
    j=0
    global cnt
    for k in range(left,right+1):
        if L[i]<=R[j]:
            A[k]=L[i]
            i+=1
            cnt+=1
        else:
            A[k]=R[j]
            j+=1
            cnt+=1
def mergeSort(A,left,right):
    if left<right:
        mid=(left+right)//2+1
        mergeSort(A,left,mid-1)
        mergeSort(A,mid,right)
        merge(A,left,mid,right)
n=int(input())
S=list(map(int,input().split()))
cnt=0
mergeSort(S,0,n-1)
print(*S)
print(cnt)
