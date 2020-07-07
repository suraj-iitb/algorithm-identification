
cnt=0
def merge(A,left,mid,right):
    global cnt
    n1=mid-left
    n2=right-mid
    L=A[left:mid]+[1000000000]
    R=A[mid:right]+[1000000000]

    i=0
    j=0
    for k in range(left,right):
        if L[i]<=R[j]:
            A[k]=L[i]
            cnt=cnt+1
            i+=1
        else:     
            A[k]=R[j]
            j+=1
            cnt=cnt+1

def mergeSort(A,left,right):
    if left+1< right:
        mid = int((left + right)/2)
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

n=int(input())
S=list(map(int,input().split()))
mergeSort(S,0,n)
print(' '.join(map(str,S)))

print(cnt)

