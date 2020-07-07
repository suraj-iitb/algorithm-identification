N = int(input())
A = list(map(int, input().split()))
cnt = 0
for i in range(len(A)-1):
    for j in range(len(A)-1, i, -1):
        if A[j] < A[j-1]:
            tmp = A[j]
            A[j] = A[j-1]
            A[j-1] = tmp
            cnt += 1
print(" ".join(map(str, A)))
print(cnt)
