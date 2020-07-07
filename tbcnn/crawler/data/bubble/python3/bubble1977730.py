N = int(input())
A = [int(i) for i in input().split()]

cnt = 0

for i in range(0, N):
    for j in range(i+1, N)[::-1]:
        if A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j]
            cnt = cnt + 1

print(' '.join([str(item) for item in A]))
print(cnt)
