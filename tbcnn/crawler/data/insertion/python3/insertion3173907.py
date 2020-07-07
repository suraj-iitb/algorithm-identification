N = int(input())
A = list(map(int, input().split()))

for k in range(N):
        print(A[k], end='')
        if k < N-1:
            print(' ', end='')
print('')

for i in range(1, N):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    for k in range(N):
        print(A[k], end='')
        if k < N-1:
            print(' ', end='')
    print('')
