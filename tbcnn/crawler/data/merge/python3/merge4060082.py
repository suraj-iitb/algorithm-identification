def merge(A, left, mid, right):

    inf = float('inf')
    L = A[left:mid]+[inf]
    R = A[mid:right] + [inf]

    i = j = 0
    for k in range(left,right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    return right - left


def mergeSort(A, left, right, count = 0):
    if left+1 < right:
        mid = (left + right)//2
        count = mergeSort(A, left, mid, count)
        count = mergeSort(A, mid, right, count)
        count += merge(A, left, mid, right)
    return count

n  = int(input())
A = list(map(int, input().split()))
ans = mergeSort(A, 0, n)
s = list(map(str, A))
print(' '.join(s))
print(ans)


