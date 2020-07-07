def showList(A, N):
    for i in range(N-1):
        print(A[i],end=' ')
    print(A[N-1])

def insertionSort(A, N):
    showList(A,N)
    for i in range(1,N):
        v = A[i]
        j = i - 1
        while j>=0 and A[j]>v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        showList(A,N)


N = int(input())
A = [int(x) for x in input().split(' ')]

A = insertionSort(A, N)
