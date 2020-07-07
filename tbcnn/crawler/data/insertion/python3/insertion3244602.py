N = int(input())
A = list(map(int, input().split()))
for i in range(1, N + 1):
    A[:i] = sorted(A[:i])
    print(*A)
