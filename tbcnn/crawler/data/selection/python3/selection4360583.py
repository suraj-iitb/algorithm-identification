n = int(input())
A = list(map(int, input().split(' ')))
c = 0

for i in range(n - 1):
    minv = A[i]
    minv_idx = i
    for k in range(i + 1, n):
        if minv > A[k]:
            minv = A[k]
            minv_idx = k
    if i != minv_idx:
        A[i], A[minv_idx] = minv, A[i]
        c += 1

print(*A)
print(c)

