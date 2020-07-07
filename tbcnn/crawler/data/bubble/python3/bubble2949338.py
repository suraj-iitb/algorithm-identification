N = int(input())
A = list(map(int, input().split()))
c , boo = 0, 1
while boo:
    boo = 0
    for n in range(N-1):
        if A[n+1] < A[n]:
            A[n+1],A[n] = A[n],A[n+1]
            c += 1
            boo = 1
print(*A)
print(c)



