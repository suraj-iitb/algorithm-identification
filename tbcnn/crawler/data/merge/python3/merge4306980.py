n = int(input())
S = list(map(int, input().split()))
count = 0


def merge(A, left, mid, right):
    global count
    n1 = mid - left
    n2 = right - mid
    L = A[left: left + n1]
    R = A[mid: mid + n2]
    L.append(float('inf'))
    R.append(float('inf'))
    i = j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        count += 1


def merge_sort(A, left, right):
    if (left + 1) < right:
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)


merge_sort(S, 0, n)
print(*S)
print(count)

