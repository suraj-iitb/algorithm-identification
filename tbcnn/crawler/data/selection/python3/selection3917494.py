def func(n, A):
    count = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if (A[j] < A[minj]):
                minj = j
        if (A[i] != A[minj]):
            A[i], A[minj] = A[minj], A[i]
            count += 1
    print (" ".join(map(str, A)))
    print (count)

n = int(input())
A = list(map(int, input().split(" ")))
func(n, A)
