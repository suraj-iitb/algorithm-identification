def InsertionSort(A, N):
    for i in range(N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        for j in range(N):
            if j == N-1:
                print(A[j])
            else:
                print(A[j], end=' ')
    return(A)

N = int(input())
A = list(map(int,input().split()))

InsertionSort(A,N)
