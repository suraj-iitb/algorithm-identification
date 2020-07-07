def insertionSort (A, N):
    for i in range(N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        printArray(A)

def printArray(A):
    for i,x in enumerate(A):
        if i != 0:
            print(" ", end="")
        print(x, end="")
    print("")

n = int(input())
a = list(int(x) for x in input().split())

insertionSort(a,n)
