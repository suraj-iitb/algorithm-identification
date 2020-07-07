def selectionSort(A, N):
    s = 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        A[i], A[minj] = A[minj], A[i]
        if i != minj:
            s += 1
    t = str(A[0])
    for i in range(1,N):
        t = t + " " + str(A[i])
    print(t)
    print(s)

n = int(input())
a = [int(i) for i in input().split()]

selectionSort(a, n)
