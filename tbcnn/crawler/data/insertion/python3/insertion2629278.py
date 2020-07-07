def insertionSort(A, N):
    for i in range(N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        t = str(A[0])
        for i in range(1,N):
            t = t + " " + str(A[i])
        print(t)


             
n = int(input())
a = [int(i) for i in input().split()]

insertionSort(a,n)
