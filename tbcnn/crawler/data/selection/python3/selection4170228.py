N = int(input())
A = list(map(int,input().split()))
count = 0

for i in range(N):
    minj = i
    for j in range(i,N):
        if A[j] < A[minj]:
            minj = j
    tmp = A[i]
    A[i] = A[minj]
    A[minj] = tmp
    if minj != i:
        count += 1
print(' '.join([str(a) for a in A])) 
print(count)
