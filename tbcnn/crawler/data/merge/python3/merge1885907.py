# Recursion / Divide and Conquer - Merge Sort
def merge(A,left,mid,right):
    global c
    n1 = mid - left
    n2 = right - mid
    L = A[left:mid] + [10**9+1]
    R = A[mid:right] + [10**9+1]
    i,j = 0,0
    for k in range(left,right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    c += right - left
def mergeSort(A,left,right):
    if left + 1 < right:
        mid = (left + right) // 2
        mergeSort(A,left,mid)
        mergeSort(A,mid,right)
        merge(A,left,mid,right)
        return A

n = int(input())
S = list(map(int, input().split()))
c=0
mergeSort(S,0,n)
print(*S)
print(c)
c=0
