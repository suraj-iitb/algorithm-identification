N, *A = map(int, open(0).read().split())
F = True
ans = 0
while F:
    F = False
    for i in range(N-1):
        if A[i] > A[i+1]:
            A[i], A[i+1] = A[i+1], A[i]
            F = True
            ans += 1
print(' '.join(map(str, A)))
print(ans)
