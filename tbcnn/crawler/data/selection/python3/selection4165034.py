N = int(input())
A = list(map(int,input().split()))

cnt = 0
for i in range(N):
    minj = i
    for j in range(i,N):
        if A[j] < A[minj]:
            minj = j
    if minj != i:
        tmp = A[minj]
        A[minj] = A[i]
        A[i] = tmp
        cnt += 1

print(" ".join([str(s) for s in A]))
print(cnt)
