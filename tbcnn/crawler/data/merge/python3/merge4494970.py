#INF = 10**9 + 1
def merge(A, left, mid, right):
    global count
    L = [A[i] for i in range(left, mid)] + [10**9 + 1]
    R = [A[i] for i in range(mid, right)] + [10**9 + 1]
    i,j = 0,0
    for k in range(left, right):
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    
def mergeSort(A, left, right):
    if left + 1 < right:
        mid = int((left + right) / 2)
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

count = 0
n = int(input())
S = list(map(int,input().split()))
mergeSort(S, 0, n)
print(*S)
print(count)
