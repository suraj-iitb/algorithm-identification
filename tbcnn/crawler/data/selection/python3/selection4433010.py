def selectionSort(A, n):
    k = 0
    for i in range (n):
        minj = i
        for j in range (i,n):
            if A[j] < A[minj]:
                minj = j
        A[i],A[minj] = A[minj],A[i]
        if i != minj:
            k += 1

    L=[str(a) for a in A]
    L=" ".join(L)
    print(L)
    print(k)



n = int(input())
A = list(map(int,input().split()))

selectionSort(A, n)
