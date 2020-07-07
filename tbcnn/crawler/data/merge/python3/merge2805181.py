def mergeSort(A, left, right, n):
    if left + 1 < right:
        mid = int((right + left ) / 2 )
        mergeSort(A, left, mid, n)
        mergeSort(A, mid, right, n)
        return (merge(A, left, mid, right, n))

def merge(A, left, mid, right, n):
    n1 = mid - left
    n2 = right - mid
    L = A[left:mid]  + [10 ** 9 + 1]
    R = A[mid:right] + [10 ** 9 + 1]
    L.append(1000000001)
    R.append(1000000001)
    i = j = 0
    for k in range(left, right):
        A[n] += 1
        if L[i] <= R[j]:
            key = L[i]
            A[k] = key
            i += 1
        else:
            key = R[j]
            A[k] = key
            j += 1
    return A

n = int(input())
A = list(map(int, input().split()))
A.append(0)
S = mergeSort(A, 0, len(A) - 1, n)
print(' '.join(list(map(str, S[:n]))))
print(S[n])
