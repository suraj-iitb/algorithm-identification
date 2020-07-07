N = int(input())
A = list(map(int, input().split()))
swap = 0
while True:
    _continue = False
    for i in range(N - 1):
        if A[i] > A[i + 1]:
            swap += 1
            _continue = True
            A[i], A[i + 1] = A[i + 1], A[i]
    if not _continue:
        break
print(*A)
print(swap)

