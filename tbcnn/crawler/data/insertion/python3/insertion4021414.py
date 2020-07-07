def InsertSort(A, N): 
    str_A = map(str, A)
    print(" ".join(str_A))
    for i in range(N - 1):
        for j in range(i + 1):
            if A[i + 1 - j] < A[i - j]:
                A[i + 1 - j], A[i - j] = A[i - j], A[i + 1 - j]
            else:
                pass
        str_A = map(str, A)
        print(' '.join(str_A))


n = int(input())
a = list(map(int, input().split()))

InsertSort(a, n)
