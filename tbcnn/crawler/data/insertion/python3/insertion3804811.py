N = int(input())
A = [int(x) for x in input().split()]

def pr(A):
    N = len(A)
    for i in range(N):
        if i != 0:
            print(" ",end = "")
        print(A[i], end = "")
    print("")

def insertionSort(A):
    N =len(A)
    for i in range(1,N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        pr(A)

pr(A)
insertionSort(A)

