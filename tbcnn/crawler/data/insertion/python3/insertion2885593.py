def print_A():
    for k, e in enumerate(A):
        if k == N - 1:
            print(e)
        else:
            print(e, end=' ')


N = int(input())
A = [int(n) for n in input().split()]
print_A()
for i in range(1, N):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    print_A()

