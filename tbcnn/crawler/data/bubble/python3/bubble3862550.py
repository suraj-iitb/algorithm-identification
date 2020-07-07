n = int(input())
A = list(map(int, input().split()))

flag = 1
count = 0
while flag:
    flag = 0
    for i in range(n-1, 0, -1):
        if A[i-1] > A[i]:
            A[i-1], A[i] = A[i], A[i-1]
            flag = 1
            count += 1
print(*A)
print(count)
