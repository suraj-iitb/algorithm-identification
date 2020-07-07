N = int(input())
A = list(map(int, input().split()))
sw = 0
for i in range(N-1):
    for j in range(N-1,i,-1):
        if A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j]
            sw += 1
print(" ".join(map(str, A)))
print(sw)
