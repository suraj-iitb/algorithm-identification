def selection_sort(A, N):
    swap_count = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            tmp = A[i]
            A[i] = A[minj]
            A[minj] = tmp
            swap_count += 1
    return A, swap_count
N = int(input())
A = list(map(int, input().split(' ')))
sorted_A, swap_count = selection_sort(A, N)
print(" ".join(map(str, sorted_A)))
print(swap_count)
