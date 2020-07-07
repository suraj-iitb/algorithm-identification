N = int(input())
A = [int(A) for A in input().split()]
cnt = 0
for i in range(1, N):
    for j in range(N-1, i-1, -1):
        if A[j] < A[j-1]:
            t = A[j]
            A[j] = A[j-1]
            A[j-1] = t
            cnt += 1
for i in range(N):
    if i == N - 1:
        print(A[i])
    else:
        print("{}".format(A[i]), end=' ')

print(cnt)
