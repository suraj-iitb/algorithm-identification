def bubble_sort(A):
    cnt = 0
    for i in range(0, len(A) - 1):
        for j in range(len(A) - 1, i, -1):
            if A[j] < A[j - 1]:
                A[j - 1], A[j] = A[j], A[j - 1]
                cnt += 1
    print(' '.join(map(str,A)))
    print(cnt)


if __name__ == '__main__':
    n = int(input())
    l = list(map(int, input().split()))
    bubble_sort(l)

