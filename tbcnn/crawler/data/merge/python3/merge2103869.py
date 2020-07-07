counter = 0

def merge(A, left, mid, right):
    L = A[left:mid]
    R = A[mid:right]
    #print(L)
    #print(R)
    L.append(float('inf'))
    R.append(float('inf'))
    i=j=0
    global counter
    for k in range(left,right):
        counter = counter+1
        if L[i]<=R[j]:
            A[k]=L[i]
            i=i+1
        else:
            A[k]=R[j]
            j=j+1

def mergeSort(A, left, right):
    if left+1<right:
        mid=(left+right)//2
        mergeSort(A,left,mid)
        mergeSort(A,mid,right)
        merge(A,left,mid,right)

n = int(input())
l = list(map(int,input().split()))
mergeSort(l,0,n)
print(*l)
print(counter)
