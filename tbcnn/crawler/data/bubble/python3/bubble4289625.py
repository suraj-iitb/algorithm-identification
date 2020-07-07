N = int(input())
A = list(map(int, input().split()))

cnt = 0
flg = True
l = 0
while flg:
    flg = False
    for i in range(l+1, N)[::-1]:
        if A[i-1] > A[i]:
            A[i], A[i-1] = A[i-1], A[i]
            cnt += 1
            flg = True
    l+=1

print(*A)
print(cnt)

