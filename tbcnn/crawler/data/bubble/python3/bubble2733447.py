def Bubble(A, N):
    f = 1
    c = 0
    while f:
        f = 0
        j = N - 1
        while j > 0:
            if A[j] < A[j - 1]:
                c += 1
                a = A[j]
                A[j] = A[j - 1]
                A[j - 1] = a
                f = 1
            j -= 1
    return A, c

N = int(input())
A = list(map(int, input().split(' ')))
A, c = Bubble(A, N)
ans = ' '.join(map(str, A)) + '\n' + str(c)
print(ans)
