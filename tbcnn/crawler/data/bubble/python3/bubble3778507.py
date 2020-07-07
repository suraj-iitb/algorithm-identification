n = int(input())

A = [int(s) for s in input().split()]

cnt = 0
flag = True
while flag:
    flag = False
    for j in range(n-1, 0, -1):
        if A[j] < A[j-1]:
            A[j-1], A[j] = A[j], A[j-1]
            flag = True
            cnt += 1

print(*A)
print(cnt)
