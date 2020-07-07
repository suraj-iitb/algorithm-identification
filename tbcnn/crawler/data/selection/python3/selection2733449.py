def Selection(A, N):
    c = 0
    i = 0
    while i < N:
        minj = i
        j = i
        while j < N:
            if A[j] < A[minj]:
                minj = j
            j += 1
        if i != minj:
            c += 1
            a = A[i]
            A[i] = A[minj]
            A[minj] = a
        i += 1
    return A, c

N = int(input())
A = list(map(int, input().split(' ')))
A, c = Selection(A, N)
print(' '.join(map(str, A)) + '\n' + str(c))
