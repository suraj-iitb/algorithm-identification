def bubblesort(N, A):
    c, flag = 0, 1
    while flag:
        flag = False
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j- 1], A[j]
                c += 1
                flag = True
    return (A, c)

A, c = bubblesort(int(input()), list(map(int, input().split())))
print(' '.join([str(v) for v in A]))
print(c)
