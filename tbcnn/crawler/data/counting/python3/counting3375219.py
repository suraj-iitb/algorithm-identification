def Countingsort(A, k, n):
    index = 0
    Out = []
    Count = [0 for i in range(k + 1)]
    for i in range(n):
        Count[A[i]] += 1
    while index <= k:
        if Count[index] > 0:
            Out.append(index)
            Count[index] -= 1
        else:
            index += 1
    print(*Out)

max = -1
n = int(input())
A = list(map(int,input().split()))
for i in range(n):
    if A[i] > max:
        max = A[i]
Countingsort(A, max, n)
