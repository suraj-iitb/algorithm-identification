
def SelectionSort(A, N):
    swap_n = 0

    for i in range(N):
        min_j = i

        for j in range(i + 1, N):
            if A[j] < A[min_j]:
                min_j = j

        if i != min_j:
            A[i], A[min_j] = A[min_j], A[i]
            swap_n += 1

    return swap_n

N = int(input())
A = [int(a) for a in input().split()]

swap_n = SelectionSort(A, N)

print(*A)
print(swap_n)
