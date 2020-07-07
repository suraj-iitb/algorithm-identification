N = int(input())
A = list(map(int, input().split()))
c = 0
for i in range(N-1):
    minj = i
    boo = 0
    for j in range(i,N):
        if A[j] < A[minj]:
            minj = j
            boo = 1
    A[i], A[minj] = A[minj], A[i]
    if boo:
        c += 1
print(*A)
print(c)

