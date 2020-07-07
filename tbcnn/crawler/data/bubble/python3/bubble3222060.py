n = int(input())
A = list(map(int, input().split(" ")))

def bubbleSort(A):
    n = len(A)
    flag = True
    i = 0
    while flag:
        flag = False
        for j in range(n-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                i += 1
                flag = True
    print(*A)
    print(i)
bubbleSort(A)
