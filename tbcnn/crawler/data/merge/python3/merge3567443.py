def merge(A, left, mid, right):
    inf = float("inf")
    L, R = A[left:mid]+[inf], A[mid:right]+[inf]

    i = j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

    return right - left


def merge_sort(A, left, right, count=0):
    if left+1 < right:
        mid = (left + right) // 2
        count = merge_sort(A, left, mid, count)
        count = merge_sort(A, mid, right, count)
        count += merge(A, left, mid, right)

    return count


if __name__ == "__main__":
    n = int(input())
    A = list(map(int, input().split()))
    count = merge_sort(A, 0, n)
    print(*A)
    print(count)
