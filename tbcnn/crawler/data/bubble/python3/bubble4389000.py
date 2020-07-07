N = int(input())
A = [int(a) for a in input().split()]

cnt = 0
flag = True
while flag:
    flag = False
    for i in reversed(range(1, N)):
        if A[i] < A[i - 1]:
            A[i], A[i - 1] = A[i - 1], A[i]
            cnt += 1
            flag = True

print(*A)
print(cnt)
