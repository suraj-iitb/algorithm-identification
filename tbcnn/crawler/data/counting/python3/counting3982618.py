
from itertools import accumulate
num = int(input())
maxnum = 10000

A = [int(x) for x in input().split()]
B = [0] * (maxnum +1)
C =[0] * (len(A)+1)
for i in A:
    B[i] += 1
B = list(accumulate(B))
for i in reversed( range(0,len(A))):
    k = A[i]
    j = B[k]
    B[k] -= 1
    C[j] = k
print(*C[1:])


