N = int(input())
A = [int(x) for x in input().split()]

for k in range(N):
    if k == N - 1:
        print(A[k])
    else:
        print(A[k], end=" ")

for i in range(1, N):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j + 1] = A[j]
        j -= 1
    A[j + 1] = v
    for k in range(N):
        if k == N - 1:
            print(A[k])
        else:
            print(A[k], end=" ")

