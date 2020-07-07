n = int(input())
A = list(map(int, input().split()))

flag = 1
i = 0
cnt = 0

while flag:
    flag = 0
    for j in range(n-1, i, -1):
        if A[j-1] > A[j]:
            tmp = A[j]
            A[j] = A[j-1]
            A[j-1] = tmp
            flag = 1
            cnt += 1
    i += 1
    
for k in range(n-1):
    print(A[k], end=' ')
print(A[n-1])
print(cnt)
