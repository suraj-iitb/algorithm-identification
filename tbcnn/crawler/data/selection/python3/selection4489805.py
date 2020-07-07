n = int(input())
A = [int(x) for x in input().split()]
cnt = 0
for i in range(n):
    minj = i
    for j in range(i,n):
        if A[j] < A[minj]:
            minj = j
    if i != minj:
        A[i],A[minj] = A[minj],A[i]
        cnt += 1

print(*A)
print(cnt)
