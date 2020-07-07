import math
count = 0
def merge(a,left,mid,right):
    global count
    # n1 = mid-left
    # n2 = right - mid
    L = A[left:mid]+[1e9]#[0]*(n1+1)
    R = A[mid:right]+[1e9]#[0]*(n2+1)
    # for i in range(n1):
        # L[i] = A[left+i]
    # for i in range(n2):
        # R[i] = A[mid+i]
    # L[n1] = 1e9
    # R[n2] = 1e9
    i, j = [0,0]
    for k in range(left,right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i+=1
        else:
            A[k] = R[j]
            j+=1
        count+=1
        
def mergesort(A,l,r):
    if (l+1) < r:
        mid = math.floor((l+r)/2)
        mergesort(A,l,mid)
        mergesort(A,mid,r)
        merge(A,l,mid,r)
N = int(input())
A = [int(x) for x in input().split(" ")]
A.append(1e9)
mergesort(A,0,N)
for i in range(len(A)):
    if i < len(A)-2:
        print(A[i],end=" ")
    else:
        print(A[i])
        break

print(count)
