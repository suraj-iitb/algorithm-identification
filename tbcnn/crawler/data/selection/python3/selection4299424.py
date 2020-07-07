N = int(input())
A = [int(i) for i in input().split()]
cntswap = 0

for i in range(0,N):
    minj = i
    for j in range(i,N):
        if A[minj] > A[j]:
            minj = j
    if i != minj:
        temp = A[i]
        A[i] = A[minj]
        A[minj] = temp
        cntswap += 1

for i in range(0, N-1):
    print(A[i], '', end='')
print(A[N-1])
print(cntswap)
