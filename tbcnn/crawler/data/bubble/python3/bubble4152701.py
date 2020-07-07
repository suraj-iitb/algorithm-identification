def show(A):
    N = len(A)
    for i in range(N):
        if i :
            print(' ', end = '')
        print(A[i], end = '')
    print()

def bubleSort(A, N):
    flag = 1
    exchange = 0
    while flag:
        flag = 0
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                exchange += 1
                flag = 1
    show(A)
    print(exchange)

N = int(input())
A = [int(i) for i in input().split()]

bubleSort(A, N)
