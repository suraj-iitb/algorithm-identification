n = int(input())
A = list(map(int,input().split()))
count = 0

for i in range(n):
    minj = i
    for j in range(i,n):
        if A[j] < A[minj]:
            minj = j
    if minj != i:
        count += 1
        a = A[i]
        A[i] = A[minj]
        A[minj] = a

print(' '.join(map(str,A)))
print(count)
