n = int(input())
A = list(map(int, input().split()))
INF = (10 ** 9) * 2
count = 0


def merge(left, mid, right):
    n1 = mid - left
    n2 = right - mid

    L = [0] * (n1 + 1)
    R = [0] * (n2 + 1)

    for i in range(n1):
        L[i] = A[left + i]

    for i in range(n2):
        R[i] = A[mid + i]

    L[n1] = INF
    R[n2] = INF

    i = 0
    j = 0

    count = 0
    for k in range(left, right):
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

    return count


def mergesort(left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        count = 0
        count += mergesort(left, mid)
        count += mergesort(mid, right)
        return count + merge(left, mid, right)
    return 0


count = mergesort(0, len(A))

print(*A)
print(count)

