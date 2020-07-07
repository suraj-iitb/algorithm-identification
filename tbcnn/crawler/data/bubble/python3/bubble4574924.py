from sys import stdin
N = int(input())
A = [int(x) for x in stdin.readline().split(' ')]

cnt = 0
for i in range(N-1):
    for j in range(0, N-1-i):
        if (A[j] > A[j + 1]):
            A[j], A[j + 1] = (A[j + 1], A[j])
            cnt += 1
print(' '.join(map(str, A)))
print(cnt)

