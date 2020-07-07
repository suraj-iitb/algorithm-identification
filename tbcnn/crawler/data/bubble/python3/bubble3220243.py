def showList(A, N):
    for i in range(N-1):
        print(A[i],end=' ')
    print(A[N-1])

def bubbleSort(A, N):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for i in range(N-1, 0, -1):
            if A[i] < A[i-1]:
                v = A[i]
                A[i] = A[i-1]
                A[i-1] = v
                flag = 1
                count += 1
    showList(A, N)
    print(count)

N = int(input())
A = [int(x) for x in input().split(' ')]
bubbleSort(A, N)
