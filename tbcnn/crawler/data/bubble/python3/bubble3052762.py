N = int(input())
*A, = list(map(int, input().split()))
flg = 1
cnt = 0
while flg:
    flg = 0
    for j in range(N-1,0,-1):
        if A[j] < A[j-1]:
            v = A[j]
            A[j] = A[j - 1]
            A[j - 1] = v
            flg = 1
            cnt += 1
print(*A)
print(cnt)
