N = int(input())
A = list(map(int, input().split()))
for i in range(1, N):
    print(*A)
    for j in range(i):
        if A[j] > A[i]:
            break
    else:
        continue
    tmp = A[i]
    for k in range(i, j, -1):
        A[k] = A[k - 1]
    A[j] = tmp
print(*A)

