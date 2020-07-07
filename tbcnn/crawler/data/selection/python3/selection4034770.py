input()
A = [int(i) for i in input().split()]
n = 0
for i in range(0, len(A)):
    minj = i
    for j in range(i, len(A)):
        if A[j] < A[minj]:
            minj = j
    A[i], A[minj] = A[minj], A[i]
    if i != minj:
        n += 1

print(" ".join(map(str, A)))
print(n)

