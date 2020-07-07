N = int(input())
A = list(map(int, input().split()))

cnt = 0

for i in range(N):
    flag = 0
    min_j = i
    for j in range(i, N):
        if A[j] < A[min_j]:
            min_j = j
            flag = 1

    if flag:
        A[i], A[min_j] = A[min_j], A[i]
        cnt += 1

print(*A)
print(cnt)

