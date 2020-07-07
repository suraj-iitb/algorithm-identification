import math

N = int(input())
A = list(map(int, input().split()))

count = 0

for i in range(0, N):
    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:
            minj = j
    if i != minj:
        count += 1
        temp = A[i]
        A[i] = A[minj]
        A[minj] = temp
    
print(' '.join(map(str, A)))
print(count)
