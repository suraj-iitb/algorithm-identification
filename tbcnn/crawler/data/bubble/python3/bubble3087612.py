def BubbleSort(A):
    n = len(A)
    ans = 0
    for i in range(n):
        for j in range(n-1, i, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                ans += 1
    print(' '.join([str(i) for i in A]))
    print(ans)

_ = input()
BubbleSort([int(i) for i in input().split()])
