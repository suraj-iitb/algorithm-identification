def bubbleSort(A, N):
    i = 0
    count = 0
    while i<N:
        for j in range(0, N-1-i):
            if A[N-j-2]>A[N-j-1]:    
                (A[N-j-1], A[N-j-2]) = (A[N-j-2], A[N-j-1])
                count += 1
        i += 1
    print(" ".join(map(str, A)))
    print(count)


n = int(input())
a = list(map(int, input().split()))
bubbleSort(a, n)
