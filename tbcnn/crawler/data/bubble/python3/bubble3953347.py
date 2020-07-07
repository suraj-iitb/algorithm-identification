N = int(input())
A = list(map(int, input().split()))
sum = 0

flag = 1
while flag:
    flag = 0
    for j in range(1, N)[::-1]:
        if A[j] < A[j-1]:
            v = A[j]
            A[j] = A[j-1]
            A[j-1] = v
            flag = 1
            sum += 1
print(*A)
print(sum)
