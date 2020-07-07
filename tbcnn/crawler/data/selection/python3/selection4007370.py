N = int(input())
A = list(map(int, input().split(' ')))

count = 0
for i in range(N-1):
    minj = i
    increment = 0
    for j in range(i+1, N):
        if A[minj] > A[j]:
            minj = j
            increment = 1
    count += increment
    A[i], A[minj] = A[minj], A[i]
print(*A)
print(count)
