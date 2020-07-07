N = int(input())
A =list(map(int, input().split()))
flag = 1
c = 0
while flag:
    flag = 0
    for i in range(N-1, 0, -1):
        if A[i] < A[i-1]:
            A[i], A[i-1] = A[i-1], A[i]
            c += 1
            flag = 1
print(*A)
print(c)
