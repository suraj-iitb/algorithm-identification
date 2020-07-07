N = int(input())
A = list(map(int, input().split()))

def insertionSort(A, N):
    for k in range(len(A)):
        if k != len(A) - 1:
            print(A[k], end=" ")
        else:
            print(A[k])
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        for k in range(len(A)):
            if k != len(A) - 1:
                print(A[k], end=" ")
            else:
                print(A[k])



insertionSort(A, N)
