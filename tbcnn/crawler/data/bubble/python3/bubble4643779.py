n = int(input())
A = list(map(int, input().split()))
count = 0
flag = 1
while flag:
    flag = 0
    for i in range(n-1, 0, -1):
        if A[i] < A[i - 1]:
            A[i], A[i-1] = A[i-1], A[i]
            flag = 1
            count += 1
print(*A,sep=' ')
print(count)
