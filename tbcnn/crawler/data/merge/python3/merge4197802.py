INFTY = float('inf')
count = 0

def merge(A, left, mid, right):
    L = A[left:mid] + [INFTY]
    R = A[mid:right] + [INFTY]
    i, j = 0, 0  
    global count 
    
    for k in range(left, right):
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def mergeSort(A, left, right):
    if left+1 < right:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

n = int(input())
S = list(map(int, input().split()))

mergeSort(S, 0, n)
print(*S)
print(count)
