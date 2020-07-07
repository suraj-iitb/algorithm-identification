N, A, cou   = int(input()), [int(temp) for temp in input().split()], 0

for i in range(N) :
    minj = i
    for j in range(i, N) :
        if A[j] < A[minj] :
            minj = int(j)
    if A[i] != A[minj] :
        A[i], A[minj] = int(A[minj]), int(A[i])
        cou = cou + 1
print(*A)
print(cou)
