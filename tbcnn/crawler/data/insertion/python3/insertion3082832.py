def pr(A):
    N = len(A);
    for i in range(N):
        if i :
            print (" ", end = "");
        print (A[i], end = "")
    print ("")

def insertionSort(A):
    pr(A)
    N = len(A)
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j = j - 1
        A[j+1] = v
        pr(A)

N = int(input())
A = [int(i) for i in input().split()]

insertionSort(A)

