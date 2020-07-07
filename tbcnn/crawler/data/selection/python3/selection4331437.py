N = int(input())
A = [int(i) for i in input().split()]

perm = 0
for i in range(N):
    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:
            minj = j
    if minj != i:
        perm += 1
    temp = A[i]
    temp2 = A[minj]
    A[i] = temp2
    A[minj] = temp
print(" ".join(list(map(str, A))))
print(perm)
