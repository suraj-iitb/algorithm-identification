N = int(input())
A = [int(s) for s in input().split()]

print(' '.join([str(item) for item in A]))
for i in range(1, N):
    key = A[i]
    j = i - 1
    while j >= 0 and A[j] > key:
        A[j+1] = A[j]
        j = j - 1
    A[j+1] = key
    print(' '.join([str(item) for item in A]))
