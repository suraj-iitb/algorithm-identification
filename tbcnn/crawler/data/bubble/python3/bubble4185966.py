N, *A = map(int, open(0).read().split())

count = 0
loop = True
while loop:
    loop = False
    for i in range(N-1, 0, -1):
        if A[i] < A[i-1]:
            A[i], A[i-1] = A[i-1], A[i]
            loop = True
            count += 1

print(' '.join([str(a) for a in A]))
print(count)
