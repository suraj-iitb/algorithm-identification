def selectionSort(A,N):
    count = 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            v = A[i]
            A[i] = A[minj]
            A[minj] = v
            count += 1
    print(" ".join(map(str,A)))
    print(count)
    
n = int(input())
numlist = [int(x) for x in input().split()]

selectionSort(numlist,n)
