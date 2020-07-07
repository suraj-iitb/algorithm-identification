N = int(input())
A = list(map(int, input().split()))

print(' '.join(map(str, A)))
for i in range(1, N):
    j = i
    while j >= 1 and A[j] < A[j-1]:
        A[j-1], A[j] = A[j], A[j-1]
        j -= 1
    print(' '.join(map(str, A)))
