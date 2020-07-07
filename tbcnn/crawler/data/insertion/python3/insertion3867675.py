N = int(input())

A = list(map(int, input().split()))

for i, a in enumerate(A):
    j = i - 1
    while j >= 0 and A[j] > a:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = a
    print(' '.join(map(str,A)))
