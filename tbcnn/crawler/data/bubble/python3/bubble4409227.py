n = int(input())
A = [int(i) for i in input().split()]

count = 0
for i in range(0, len(A)-1):
    for j in range(len(A)-1, i, -1):
        if A[j-1]>A[j]:
            A[j-1], A[j] = A[j], A[j-1]
            count += 1

print(*A)
print(count)

