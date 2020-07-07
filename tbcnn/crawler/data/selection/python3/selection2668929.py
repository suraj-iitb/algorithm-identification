def selection_sort(A):
    n = len(A)
    swap_cnt = 0
    for i in range(n):
        mini = i
        for j in range(i, n):
            if A[j] < A[mini]:
                mini = j
        if mini != i:
            A[i], A[mini] = A[mini], A[i]
            swap_cnt += 1
    return A, swap_cnt

n = int(input())
A = list(map(int, input().split()))
A, swap_cnt = selection_sort(A)
print(' '.join(list(map(str, A))))
print(swap_cnt)

