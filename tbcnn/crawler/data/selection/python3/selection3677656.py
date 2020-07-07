n = int(input())
A = list(map(int, input().split()))
numchange = 0

for i in range(n):
    minj = i
    for j in range(i, n):
        if A[j] < A[minj]:
            minj = j
    if A[i] != A[minj]:
        tmp = A[i]
        A[i] = A[minj]
        A[minj] = tmp
        numchange += 1
        
print(str(A).replace(',', '')[1:-1])
print(numchange)
    
