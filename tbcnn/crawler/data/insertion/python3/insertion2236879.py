tim = int(input())
A   = [int(A) for A in input().split()]
for i in range(tim) :
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v :
        A[j + 1] = A[j]
        j -= 1
        A[j + 1] = v
    A2 = list(map(str, A))
    print(' '.join(A2))
