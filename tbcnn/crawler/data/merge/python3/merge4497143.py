def merge(A,left,mid,right):
    global cnt
    n1 = mid - left
    n2 = right - mid
    cnt += n1+n2
    L = [A[left+i] for i in range(n1)]
    R = [A[mid+i] for i in range(n2)]
    L.append(float("inf"))
    R.append(float("inf"))
    i = 0
    j = 0
    for k in range(left,right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def mergesort(A,left,right):
    if left +1 < right:
        mid = int((left+right)/2)
        mergesort(A,left,mid)
        mergesort(A,mid,right)
        merge(A,left,mid,right)

n = int(input())
A = list(map(int,input().split()))
cnt = 0
mergesort(A,0,n)
print(" ".join(map(str,A)))
print(cnt)
