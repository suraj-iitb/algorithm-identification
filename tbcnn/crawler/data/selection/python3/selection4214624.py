N = int(input())
A = [int(a) for a in input().split()]
cnt = 0
for i in range(N):
    minj = i
    for j in range(i+1, N):
        if A[j] < A[minj]:
            minj = j
    if minj != i:
        tmp = A[i]
        A[i] = A[minj]
        A[minj] = tmp
        cnt += 1
A = [str(a) for a in A]
print(" ".join(A))
print(cnt)
