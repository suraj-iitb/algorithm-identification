def selection_sort(A):
    n = len(A)
    num_swaps = 0
    for i in range(n):
        min_idx = i
        for j in range(i, n):
            if A[j] < A[min_idx]:
                min_idx = j
        if min_idx != i:
            A[i], A[min_idx] = A[min_idx], A[i]
            num_swaps += 1
    return num_swaps


N = int(input())
A = [int(elem) for elem in input().split()]
num_swaps = selection_sort(A)
print(*A)
print(num_swaps)

