N = int(input())
A = list(map(int, input().split()))

def bubbleSort(A, N):
    counter = 0
    i = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(N-1, i, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                flag = 1
                counter += 1
        i += 1
    print(" ".join(map(str, A)), counter, sep="\n")
bubbleSort(A, N)
