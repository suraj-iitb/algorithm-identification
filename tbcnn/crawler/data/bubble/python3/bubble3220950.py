n = int(input())
A = list(map(int, input().split()))
nums = [n - i for i in range(1, n)]
flag = 1
exchange = 0

while flag == 1:
    flag = 0
    for j in nums:
        if A[j] < A[j - 1]:
            A[j], A[j - 1] = A[j - 1], A[j]
            exchange += 1
            flag = 1
        else:
            pass
        
print(*A)
print(exchange)
