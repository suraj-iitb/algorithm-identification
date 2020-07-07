def prList(A):
    n = len(A)
    for i in range(n):
        if i:
            print(" ", end="")
        print(A[i], end="")
    print("")


def insertSort(A):
    n = len(A)
    for i in range(1, n):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        prList(A)


n = int(input())
A = [int(i) for i in input().split()]
prList(A)
insertSort(A)

