N = int(input())
*A, = map(int, input().split())
flag = 1
cnt = 0
while flag:
    flag = 0
    for j in range(N-1, 0, -1):
        if A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j]
            flag = 1
            cnt += 1
print(*A)
print(cnt)
