def trace(X):
    for i in range(len(X)):
        print(X[i], end='')
        if i != len(X) - 1:
            print(' ', end='')
    print('')


N = int(input())
A = [int(i) for i in input().split()]

for i in range(1, N):
    trace(A)
    v = A[i]
    j = i - 1

    while (j >= 0) and (A[j] > v):
        A[j + 1] = A[j]
        j -= 1

    A[j + 1] = v
trace(A)

