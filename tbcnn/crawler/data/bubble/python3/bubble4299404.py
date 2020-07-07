N = int(input())
A = [int(i) for i in input().split()]
cntswap = 0


for i in range(1,N):
    for j in range(i, 0, -1):
        if A[j-1] > A[j]:
            A[j-1:j+1] = [A[j], A[j-1]]
            cntswap += 1

for i in range(0, N-1):
    print(A[i], '', end='')
print(A[N-1])
print(cntswap)
