count=0
def merge(A,left,mid,right):
    global count
    L=A[left:mid]+[10**9+1]
    R=A[mid:right]+[10**9+1] 
    i=0
    j=0
    for k in range(left,right):
        count+=1
        if L[i]<=R[j]:
            A[k]=L[i]
            i+=1
        else:
            A[k]=R[j]
            j+=1
       
def mergeSort(A,left,right):
    if left+1<right:
        mid=(left+right)//2
        mergeSort(A,left,mid)
        mergeSort(A,mid,right)
        merge(A,left,mid,right)

n=int(input())
S=[int(i) for i in input().split()]
mergeSort(S,0,n)
print(*S)
print(count)
