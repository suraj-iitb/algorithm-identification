def BubbleSort(A):
    nswap = 0
    for i in range(len(A)):
        for j in range(len(A)-1,i,-1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                nswap += 1
    return nswap, A

input()
a = list(map(int, input().split()))

ns, sa = BubbleSort(a)
print(' '.join(map(str, sa)))
print(ns)
