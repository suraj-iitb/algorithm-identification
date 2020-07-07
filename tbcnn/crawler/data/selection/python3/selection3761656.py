def selectionSort(A, N):
    swap_count = 0

    for i in range(0, N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        A[i], A[minj] = A[minj], A[i]
        if i != minj:
            swap_count += 1

    return swap_count


if __name__ == "__main__":
    N = int(input())
    numbers = input().split(" ")
    for i in range(len(numbers)):
        numbers[i] = int(numbers[i])

    swap_count = selectionSort(numbers, N)

    print(*numbers)
    print(swap_count)
