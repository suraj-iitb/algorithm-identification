N = int(input())
A = [int(a) for a in input().split()]
print(*A)

for i in range(1, N):
    v = A[i]
    j = i - 1
    while 0 <= j and v < A[j]:
        A[j + 1] = A[j]
        j -= 1
    A[j + 1] = v
    print(*A)
