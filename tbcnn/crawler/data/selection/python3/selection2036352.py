N = int(input())
A = [int(i) for i in input().split()]
counter = 0
for i in range(N):
    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:
            minj = j
    if A[i] != A[minj]:
        A[i], A[minj] = A[minj], A[i]
        counter += 1

print(' '.join([str(A[i]) for i in range(N)]))
print(counter)
