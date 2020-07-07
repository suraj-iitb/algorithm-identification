import math

N = int(input())
A = list(map(int, input().split()))

flag = 1
count = 0

while flag:
    flag = 0
    for j in range(N-1, 0, -1):
        if A[j] < A[j-1]:
            temp = A[j]
            A[j] = A[j-1]
            A[j-1] = temp
            count += 1
            flag = 1
print(' '.join(map(str, A)))
print(count)
            
