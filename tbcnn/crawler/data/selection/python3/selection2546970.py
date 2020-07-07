
N = (int)(input())
A = list(map(int,input().split()))

swapOperation = 0

for i in range(0,N):
    minj = i
    for j in range(i,N):
        if A[j] < A[minj]:
            minj = j
    if minj != i:
        v = A[i]
        A[i] = A[minj]
        A[minj] = v
        swapOperation += 1

print(' '.join(map(str,A)))
print(swapOperation)
