INF = 10000000000

def merge(A, left, mid, right):
    global anw

    L = A[left:mid] + [INF]
    R = A[mid:right] + [INF]

    i, j= 0, 0

    for k in range(left, right):
        anw += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def mergeSort(A, left, right):
    global anw
    if left + 1 < right:
        mid = int(( left + right ) / 2)
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

if __name__ == '__main__':
    n = int(input())
    S = [int(x) for x in input().split()]
    anw = 0
    mergeSort(S, 0, n)
    print(*S)
    print(anw)
