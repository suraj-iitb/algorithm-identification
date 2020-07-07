def selectionSort(A,N):
    b = 0
    for i in range(0,N):
        minj = i
        for j in range(i,N):
            if A[minj] > A[j]:
                minj = j
        A[i],A[minj] = A[minj],A[i]
        if minj != i:
            b += 1
        
    print(*A)
    print(b)

N = int(input())
A = list(map(int,input().split()))

selectionSort(A,N)
