def merge(A, left, mid, right):
    global cnt
    n1 = mid - left
    n2 = right - mid
    L = A[left:mid] + [INF]
    R = A[mid:right] + [INF]
    i = 0
    j = 0
    for k in range(left,right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1
        cnt += 1

def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right)//2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

INF = 10000000000
n = int(input())
S = list(map(int,input().split()))
cnt = 0
mergeSort(S,0,n)
print(*S)
print(cnt)
