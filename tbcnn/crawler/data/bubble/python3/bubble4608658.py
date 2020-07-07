# Bubble Sort
N = int(input())
A = list(map(int, input().split()))
swapCnt = 0
for i in range(len(A)-1):
    for j in range(len(A)-1, i, -1):
        if A[j] < A[j-1]:
            A[j], A[j - 1] = A[j - 1], A[j]
            swapCnt += 1
print(' '.join(map(str, A)))
print(swapCnt)

