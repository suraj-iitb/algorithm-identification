N = int(input())
A = list(map(int, input().split()))
for i in range(1, N):
    for k in range(N):
        if k != N - 1:
            print(A[k], end=" ")
        else:
            print(A[N-1], end="")
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j + 1] = A[j]
        j -= 1
    A[j + 1] = v
    print()
for k in range(N):
    if k != N - 1:
        print(A[k], end=" ")
    else:
        print(A[N-1])

