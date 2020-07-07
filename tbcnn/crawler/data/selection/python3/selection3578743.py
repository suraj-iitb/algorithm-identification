N = int(input())
A = list(map(int, input().split()))

minv = A[0]
sw = 0
for i in range(N):
    minv = min(A[i:])
    mini = A[i:].index(minv) + i
    if A[i] > minv:
        temp = A[i]
        A[i] = minv
        A[mini] = temp
        sw += 1

print(*A)
print(sw)
