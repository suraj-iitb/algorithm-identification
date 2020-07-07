n = int(input())
A = [int(i) for i in input().split()]
count = 0
for i in range(n):
    minj = i
    for j in range(i,n):
        if A[j] < A[minj]:
            minj = j
            
    A[i],A[minj] = A[minj],A[i]
    if minj != i:
        count += 1
print(" ".join(map(str,A)))
print(count)
