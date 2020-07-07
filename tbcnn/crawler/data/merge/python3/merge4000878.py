n,*a=map(int,open(0).read().split())

c=0
left=0
right=n
def merge(A,left,mid,right):
    global c
    L=A[left:mid]+[float("inf")]
    R=A[mid:right]+[float("inf")]
    i=0
    j=0
    for r in range(left,right):
        if L[j]>R[i]:
            c+=1
            A[r]=R[i]
            i+=1
        else:
            c+=1
            A[r]=L[j]
            j+=1

def mergesort(A,left,right):
    if left+1<right:
        mid=(left+right)//2
        mergesort(A,left,mid)
        mergesort(A,mid,right)
        merge(A,left,mid,right)
        
mergesort(a,left,right)

print(*a)
print(c)
