N = int(input())
A = [int(a) for a in input().split(" ")]
swop = 0
for i, a in enumerate(A):
    j = N - 1
    while j >= i + 1:
        if A[j] < A[j - 1]:
            tmp = A[j]
            A[j] = A[j - 1]
            A[j - 1] = tmp
            swop += 1
        j -= 1
print(" ".join([str(a) for a in A]))
print(swop)
