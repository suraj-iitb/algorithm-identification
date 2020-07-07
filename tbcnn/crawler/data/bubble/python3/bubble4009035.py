n = int(input())
A = list(map(int, input().split()))
cnt = 0
i = 0
flag = 1
while flag:
    flag = 0
    for j in range(n-1,i,-1):
        if A[j] < A[j-1]:
            buff = A[j-1]
            A[j-1]=A[j]
            A[j] = buff
            flag = 1
            cnt += 1
    i += 1
for k in range(n):
    if k != n-1:
        print(A[k],"",end="")
    else:
        print(A[k])
print(cnt)
