def func(n, A):
    flag = True
    count = 0
    i = 0
    while (flag):
        flag = False
        for j in reversed(range(i+1, n)):
            if (A[j] < A[j-1]):
                A[j], A[j-1] = A[j-1], A[j]
                flag = True
                count += 1
        i += 1
    print (" ".join(map(str, A)))
    print (count)

n = int(input())
A = list(map(int, input().split(" ")))
func(n, A)
