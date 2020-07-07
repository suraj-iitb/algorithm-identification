
num_length = int(input())
num_array = [int(x) for x in input().split()]


def selectionsort(A, N):
    exchange_counter = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j

        if i != minj:
            A[i], A[minj] = A[minj], A[i]
            exchange_counter += 1

    print(" ".join(map(str, A)))
    print(exchange_counter)

selectionsort(num_array, num_length)
