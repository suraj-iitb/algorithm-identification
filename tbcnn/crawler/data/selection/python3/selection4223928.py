N = int(input())
A = list(map(int, input().split()))
swap = 0
for i in range(N - 1):
    _i = i
    _min = A[i]
    for j in range(i + 1, N):
        if A[j] < _min:
            _i = j
            _min = A[j]
    if i != _i:
        swap += 1
        A[i], A[_i] = A[_i], A[i]
print(*A)
print(swap)

