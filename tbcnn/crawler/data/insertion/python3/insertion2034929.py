N = int(input())
A = [int(i) for i in input().split()]
print(' '.join([str(A[i]) for i in range(0, N)]))
for i in range(1, N):
    v = int(A[i])
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    print(' '.join([str(A[i]) for i in range(0, N)]))
