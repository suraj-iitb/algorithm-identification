INFTY = 10 ** 9
count = 0

def merge(A, left, mid, right):
    global count

    n1 = mid - left
    n2 = right - mid

    L = A[left:mid] + [INFTY]
    R = A[mid:right] + [INFTY]

    i = 0
    j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        
        count += 1


def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)



n = int(input())
S = list(map(int, input().split()))

mergeSort(S, 0, len(S))
print(*S)
print(count)
