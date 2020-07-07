n = int(input())
A = [int(_) for _ in input().split()]

c = 0
for i in range(n):
    minj = i
    for j in range(i+1, n):
        if A[j] < A[minj]:
            minj = j
    t = A[i]
    A[i] = A[minj]
    A[minj] = t
    if i != minj:
        c += 1
print(' '.join(map(str, A)))
print(c)
