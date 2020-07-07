# Selection Sort
N = int(input())
A = list(map(int, input().split()))
swapCnt = 0
for i in range(N):
    minNum = i
    for j in range(i, N):
        if A[j] < A[minNum]:
            minNum = j
    if minNum != i:
        A[minNum], A[i] = A[i], A[minNum]
        swapCnt += 1
print(' '.join(map(str, A)))
print(swapCnt)

