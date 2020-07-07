n = int(input())
A = list(map(int, input().split()))

maxA = max(A) + 1
B = [0] * n
C = [0] * maxA

for a in A:
    C[a] += 1
    
j = 0
for i in range(maxA):
    for k in range(C[i]):
        B[j] = i
        j += 1
        
print(" ".join(map(str, B)))
