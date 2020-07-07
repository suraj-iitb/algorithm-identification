def print_A():
    for i, n in enumerate(A):
        if i == N - 1:
            print(A[i])
        else:
            print(A[i], end=' ')

N = int(input())
A = [int(n) for n in input().split()]
cnt = 0
flg = 0
for i in range(N):
    min_j = i
    for j in range(i, N):
        if A[j] < A[min_j]:
            min_j = j
            flg = 1
    if flg == 1:
        cnt += 1
        flg = 0
        w = A[i]; A[i] = A[min_j]; A[min_j] = w
print_A()
print(cnt)

