N, A = int(input()), list(map(int, input().split()))
print(' '.join([str(a) for a in A]))
for i in range(1, N):
    v= A[i]
    j= i - 1
    while j  >= 0 and A[j] > v:
        A[j + 1] = A[j]
        j -= 1
    A[j + 1] = v
    print(' '.join([str(a) for a in A]))
