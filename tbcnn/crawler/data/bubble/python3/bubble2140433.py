
num_length = int(input())
num_array = [int(x) for x in input().split()]

def bubbleSort(A, N):
    flag = 1
    exchange_counter = 0
    while flag:
        flag = 0
        for i in range(1, N):
            if A[i] < A[i-1]:
                A[i], A[i-1] = A[i-1], A[i]
                flag = 1
                exchange_counter += 1
    print(" ".join(map(str, A)))
    print(exchange_counter)

bubbleSort(num_array, num_length)
