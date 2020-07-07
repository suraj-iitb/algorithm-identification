N, *A = map(int, open(0).read().split())

count = 0
for i in range(N):
    min_j = i
    for j in range(i, N):
        if A[j] < A[min_j]: 
            min_j = j
    if min_j != i:
        A[i], A[min_j] = A[min_j], A[i]
        count += 1

print(' '.join([str(a) for a in A]))
print(count)
