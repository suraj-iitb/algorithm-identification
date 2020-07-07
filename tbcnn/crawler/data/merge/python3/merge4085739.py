inf = 10000000000

def merge_sort(A, left, right, count):
    if left + 1 < right:
        mid = (left + right) // 2
        count_l = merge_sort(A, left, mid, count)
        count_r = merge_sort(A, mid, right, count)
        return merge(A, left, mid, right) + count_l + count_r
    return 0

def merge(A, left, mid, right):
    L = A[left:mid] + [inf]
    R = A[mid:right] + [inf]

    i = j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    
    return right - left

if __name__ == "__main__":
    n = int(input())
    *A, = map(int, input().split())
    ans = merge_sort(A, 0, n, 0)
    print(*A)
    print(ans)
