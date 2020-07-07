def selectionSort(A, N):
    swap_count = 0
    for i in range(N):
        minj = i
        for j in range(i + 1, N):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            A[minj], A[i] = A[i], A[minj]
            swap_count += 1
    return swap_count


if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    count = selectionSort(A, N)
    print(' '.join(map(str, A)))
    print(count)

