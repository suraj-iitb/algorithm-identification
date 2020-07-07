N = int(input())
A = list(map(int, input().split()))

ans = 0
f = True
while f:
    f = False
    for i in range(N - 1, 0, -1):
        if A[i-1] > A[i]:
            A[i], A[i-1] = A[i-1], A[i]
            ans += 1
            f = True
s = ''
for a in A:
    s += str(a) + ' '
print(s.rstrip())
print(ans)

