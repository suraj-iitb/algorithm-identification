
def merge(A, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    
    L = A[left:mid] + [float("inf")]
    R = A[mid:right] + [float("inf")]

    i = 0
    j = 0

    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

    return right - left

def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        cnt1 = mergeSort(A, left, mid)
        cnt2 = mergeSort(A, mid, right)
        cnt3 = merge(A, left, mid, right)
        return cnt1 + cnt2 + cnt3
    else:
        return 0

n = int(input())
S = [int(s) for s in input().split()]

ans = mergeSort(S, 0, n)

print(*S)
print(ans)
