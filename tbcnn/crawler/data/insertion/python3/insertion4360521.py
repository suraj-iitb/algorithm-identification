n = int(input())
A = list(map(int, input().split(' ')))

print(*A)
for i in range(1, n):
    t = A[i]
    k = i - 1
    while k >= 0 and t < A[k]:
        A[k + 1] = A[k]
        k -= 1
    A[k + 1] = t
    print(*A)

