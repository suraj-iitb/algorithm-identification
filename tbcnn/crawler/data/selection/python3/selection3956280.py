N = int(input())
A = [int(i) for i in input().split()]
counter = 0
for i in range(N):
    minj = i
    for j in range(i+1, N):
        if A[j] < A[minj]:
            minj = j
    if minj != i:
        A[i], A[minj] = A[minj], A[i]
        counter += 1
    
print(' '.join([str(i) for i in A]))
print(counter)
