N = int(input())
A = [int(i) for i in input().split()]

def bubbleSort(A, N):
    count = 0
    flag = 1
    while flag:
        flag = 0
        for i in range(N-1, 0, -1):
            if A[i] < A[i-1]:
                tmp = A[i]
                A[i] = A[i-1]
                A[i-1] = tmp
                flag = 1
                count += 1
    return A, count

A, count = bubbleSort(A, N)
print(' '.join([str(i) for i in A]))
print(count)
