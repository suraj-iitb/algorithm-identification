N = int(input())
A = [int(x) for x in input().split()]

def BubbleSort(A):
    N = len(A)
    count = 0
    flag = 1
    i = 0
    while flag:
        flag = 0
        for j in reversed(range(i+1,N)):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                count += 1
                flag = 1
        i += 1
    for k in range(N-1):
        print(A[k], end=" ")
    print(A[N-1])
    print(count)

BubbleSort(A)

