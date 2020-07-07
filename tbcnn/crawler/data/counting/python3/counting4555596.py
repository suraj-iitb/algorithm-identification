from itertools import accumulate

N = int(input())
A = list(map(int, input().split()))

C = [0]*(max(A)+1)
B = [0]*N

for a in A:
    C[a] += 1

C = list(accumulate(C))

for a in A[::-1]:  
    C[a] -= 1
    B[C[a]] = a

print(*B)
