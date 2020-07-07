def selectionSort(N, A):
    c=  0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            A[i], A[minj] = A[minj], A[i]
            c += 1
    return (A, c)


A, c = selectionSort(int(input()), list(map(int, input().split())))
print(*A)
print(c)
