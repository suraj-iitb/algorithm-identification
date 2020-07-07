N = int(input())
A = list(map(int, input().split()))

C = [0]*10001
for i in A:
    C[i] += 1

tmp = C[0]
for i in range(1, 10001):
    C[i] += tmp
    tmp = C[i]

ans = [0]*N
for i in range(N-1, -1, -1):
    tmp = A[i]
    ix = C[tmp]-1
    ans[ix] = tmp
    C[tmp] -= 1

print(*ans, sep=' ')
