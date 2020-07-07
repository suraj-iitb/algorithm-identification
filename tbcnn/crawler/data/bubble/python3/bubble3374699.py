def bubble_sort(A, N):
    flag = True
    exchange_count = 0
    while flag:
        flag = False
        for j in reversed(range(1,N)):
            if A[j] < A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                flag = True
                exchange_count += 1
    print(*A)
    print(exchange_count)

N = int(input())
A = list(map(int, input().split()))
bubble_sort(A,N)
