N = int(input())
A = list(map(int, input().split()))

for i in range(1, N):
    print(" ".join(map(str, A)))
    for j in range(i-1, -1, -1):
        if A[j] < A[j+1]:
            break
        A[j], A[j+1] = A[j+1], A[j]
print(" ".join(map(str, A)))

