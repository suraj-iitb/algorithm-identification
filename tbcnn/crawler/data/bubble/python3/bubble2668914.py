def bubble_sort(A):
    swap_cnt = 0
    for i in range(len(A)):
        for j in range(len(A) - 1, i, -1):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                swap_cnt += 1
    return A, swap_cnt


n = int(input())
A = list(map(int, input().split()))
A, swap_cnt = bubble_sort(A)
print(' '.join(map(str, A)))
print(swap_cnt)

