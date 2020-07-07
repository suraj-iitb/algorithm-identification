N = int(input())
A = [int(x) for x in input().split()]
count = 0
for i in range(0, N):
    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:
            minj = j
    A[i], A[minj] = A[minj], A[i]
    if A[i] != A[minj]:
        count += 1
print(' '.join([str(x) for x in A]))
print(count)
