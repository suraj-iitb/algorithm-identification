N = int(input())
*A, = map(int, input().split())
cnt = 0
for i in range(N):
    min = i
    for j in range(i, N):
        if A[min]  > A[j]:
            min = j
    if min != i:
        A[i], A[min] = A[min], A[i]
        cnt += 1
print(*A)
print(cnt)
