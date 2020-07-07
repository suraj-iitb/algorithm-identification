input()
A = [int(v) for v in input().split(" ")]

def swap(A, i, j):
    t = A[i]
    A[i] = A[j]
    A[j] = t

swap_count = 0
for i in range(0, len(A) - 1):
    minJ = i
    for j in range(i, len(A)):
        if A[j] < A[minJ]:
            minJ = j

    if i != minJ:
        swap(A, i, minJ)
        swap_count += 1

print(" ".join([str(v) for v in A]))
print(swap_count)
