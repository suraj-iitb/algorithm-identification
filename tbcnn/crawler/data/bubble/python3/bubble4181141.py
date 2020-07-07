N = int(input())
A = list(map(int, input().split()))

flag = 1
cnt = 0
while flag:
    flag = 0
    for j in reversed(range(1, N)):
        if A[j] < A[j-1]:
            cnt += 1
            tmp = A[j]
            A[j] = A[j-1]
            A[j-1] = tmp
            flag = 1
print(' '.join([str(i) for i in A]))
print(cnt)

