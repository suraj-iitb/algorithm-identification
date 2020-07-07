N = int(input())
A = list(map(int, input().split()))

print(' '.join(map(str, A)))

for i in range(1,N):
    v = A[i]
    j = i-1
    while v < A[j] and j >= 0:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    print(' '.join(map(str, A)))

