N = int(input())
*A, = map(int, input().split())
flag = 1
i = 0
count = 0
while i < N-1:
    for j in range(N-1, i, -1):
        if A[j] < A[j-1]:
            tmp = A[j]
            A[j] = A[j-1]
            A[j-1] = tmp
            count += 1
    i += 1
        
print(*A)
print(count)
