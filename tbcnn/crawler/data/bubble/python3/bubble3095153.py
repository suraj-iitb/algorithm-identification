N = int(input())
A = list(map(int, input().split() ) )

cnt = 0
for i in range(N-1):
    for j in range(N-1, i, -1):
        if A[j] < A[j-1]:
            cnt += 1
            tmp = A[j]
            A[j] = A[j-1]
            A[j-1] = tmp

print(' '.join(map(str, A)) )
print(cnt)
