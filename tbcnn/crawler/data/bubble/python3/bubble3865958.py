input()
A = [int(v) for v in input().split(' ')]

swap_count = 0
def swap(A, i, j):
    t = A[i]
    A[i] = A[j]
    A[j] = t

for i in range(0, len(A)):
    for j in range(len(A) - 1, i, -1):
        if A[j] < A[j-1]:
            swap(A, j, j-1)
            swap_count += 1

print(" ".join([str(v) for v in A]))
print(swap_count)


