def func(n, A):
    for i in range(1, n):
        print (" ".join(map(str, A)))
        v = A[i]
        j = i-1
        while (j >= 0 and A[j] > v):
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
    print (" ".join(map(str, A)))

n = int(input())
A = list(map(int, input().split(" ")))
func(n, A)
