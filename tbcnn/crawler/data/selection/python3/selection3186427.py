N = int(input())
A = list(map(int,input().split()))
count = 0
for i in range(0,N-1):
    minj = i
    for j in range(i,N):
        if A[j] < A[minj]:
            minj = j
    if i != minj:
        A[i],A[minj] = A[minj],A[i]
        count += 1
print(*A)
print(count)

