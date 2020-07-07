N = int(input())
A = [int(n) for n in input().split()]
flag = 1
cnt = 0
while flag:
    flag = 0
    for i in range(N-1, 0, -1):
        if A[i] < A[i-1]:
            w = A[i-1]; A[i-1] = A[i]; A[i] = w
            cnt += 1
            flag = 1

for i, n in enumerate(A):
    if i == N - 1:
        print(n)
    else:
        print(n, end=' ')

print(cnt)

