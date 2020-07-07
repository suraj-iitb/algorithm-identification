N = int(input())
A = list(map(int, input().split()))
count = 0

for i in range(N):
    for j in range(N - 1, i, -1):
        if A[j] < A[j-1]:
            A[j], A[j - 1] = A[j -1], A[j]
            count += 1

print(*A)
print(count)
