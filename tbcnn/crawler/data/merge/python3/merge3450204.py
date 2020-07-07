count = 0


def merge(A, left, mid, right):
    L = A[left:mid] + [float('INF')]
    R = A[mid:right] + [float('INF')]
    i = 0
    j = 0
    # 右と左比べて小さい方をとってくる
    for k in range(left, right):
        global count
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1


def mergeSort(A, left, right):
    if left+1 < right:
        mid = (left + right)//2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)


n = int(input())
A = list(map(int, input().split()))
mergeSort(A, 0, len(A))
print(*A)
print(count)

