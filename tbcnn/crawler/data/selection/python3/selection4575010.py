from sys import stdin
N = int(input())
A = [int(x) for x in stdin.readline().split(' ')]

cnt = 0
for i in range(0, N):
    minj = i
    for j in range(i, N):
        if (A[minj] > A[j]):
            minj = j
    if (minj != i):
        A[minj], A[i] = (A[i], A[minj])
        cnt += 1

print(' '.join(map(str, A)))
print(cnt)

