def insertionSort(A,N):
    for i in range(N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print(" ".join(map(str,A)))

n = int(input())
numlist = [int(x) for x in input().split()]

insertionSort(numlist,n)
