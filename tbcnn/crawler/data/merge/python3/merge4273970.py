def merge(A, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    L = []
    R = []

    for i in range(n1):
        L.append(A[left+i])
    for i in range(n2):
        R.append(A[mid+i])

    L.append(10**9)
    R.append(10**9)

    i = 0
    j = 0

    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1
    return right - left

def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right)//2
        return mergeSort(A, left, mid) + mergeSort(A, mid, right) + merge(A, left, mid, right)
    else:
        return 0

n = int(input())
X = list(map(int, input().split()))
x = mergeSort(X, 0, n)

print(" ".join(map(str, X)))
print(x)
