INF = int(1e18)

def merge(A, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    L = [A[left + i] for i in range(n1)]
    R = [A[mid + i] for i in range(n2)]
    L.append(INF)
    R.append(INF)
    i, j = 0, 0
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

def merge_sort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        c1 = merge_sort(A, left, mid)
        c2 = merge_sort(A, mid, right)
        c = merge(A, left, mid, right)
        return c + c1 + c2
    else:
        return 0

if __name__ == '__main__':
    n = int(input())
    A = list(map(int, input().split()))
    c = merge_sort(A, 0, n)

    print(" ".join(map(str, A)))
    print(c)
