N = int(input())
A = list(map(int, input().split()))

for i in range(1, N+1):
    for j in reversed(range(1, i)):
        if A[j] < A[j-1]:
            tmp = A[j]
            A[j] = A[j-1]
            A[j-1] = tmp
        else:
            break

    result = [str(k) for k in A]
    print(' '.join(result))

