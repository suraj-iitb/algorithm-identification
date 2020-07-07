if __name__ == '__main__':
    import sys
    input = sys.stdin.readline

    MAX = 500000
    SENTINEL = 2000000000

    L = [None]*(MAX//2+2)
    R = [None]*(MAX//2+2)
    cnt = 0

    def merge(A, n ,left, mid, right, cnt):
        n1 = mid - left
        n2 = right - mid
        for i in range(n1):
            L[i] = A[left + i]
        for i in range(n2):
            R[i] = A[mid + i]
        L[n1] = R[n2] = SENTINEL
        i, j = 0, 0
        for k in range(left, right):
            cnt += 1
            if L[i] <= R[j]:
                A[k] = L[i]
                i += 1
            else:
                A[k] = R[j]
                j += 1
        return cnt

    def mergeSort(A, n, left, right, cnt):
        if left+1 < right:
            mid = (left + right)//2
            cnt = mergeSort(A, n, left, mid, cnt)
            cnt = mergeSort(A, n, mid, right, cnt)
            cnt = merge(A, n, left, mid, right, cnt)
        return cnt

    n = int(input())

    A = list(map(int, input().split()))

    cnt = mergeSort(A, n, 0, n, cnt)

    print(' '.join(map(str, A)))
    print(cnt)

