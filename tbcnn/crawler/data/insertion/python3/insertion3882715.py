N = int(input())
A = [int(x) for x in input().split()]

for i in range(N):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1 
        A[j+1] = v
    for _ in range(N):
        if _ == N-1:
            print(A[_],sep='',end='')
        else:
            print(A[_], sep='',end=' ')
    print()