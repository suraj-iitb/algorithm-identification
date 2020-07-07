n = int(input())
A = list(map(int, input().split(' ')))

f = 1
c = 0
while f:
    f = 0
    for i in range(1, n)[::-1]:
        if A[i - 1] > A[i]:
            A[i - 1], A[i] = A[i], A[i - 1]
            c += 1
            f = True

print(*A)
print(c)

