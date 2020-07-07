def show(A):
    N = len(A)
    for i in range(N):
        if i :
            print(' ', end = '')
        print(A[i], end = '')
    print()

def selectionSort(A, N):
    exchange = 0
    for i in range(N):
        min_j = i
        for j in range(i, N):
            if A[j] < A[min_j]:
                min_j = j
        if min_j != i:
            A[i], A[min_j] = A[min_j], A[i]
            exchange += 1
    show(A)
    print(exchange)

N = int(input())
A = [int(i) for i in input().split()]

selectionSort(A, N)
