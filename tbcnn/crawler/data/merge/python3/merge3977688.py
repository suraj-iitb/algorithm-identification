def merge(A, left, mid, right):
    count = 0
    INF = 1_000_000_001
    n1 = mid - left
    n2 = right - mid
    L = A[left:mid] + [INF]
    R = A[mid:right] + [INF]

    i, j = 0, 0

    for k in range (left, right):
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

    return count

def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        countL = mergeSort(A, left, mid)
        countR = mergeSort(A, mid, right)
        return merge(A, left, mid, right) + countL + countR
    return 0


if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    count = mergeSort(nums, 0, n)
    print(*nums)
    print(count)

