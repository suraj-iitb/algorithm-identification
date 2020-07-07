n = int(input())
A = list(map(int, input().split()))
A.insert(0,0) 
B = [-1 for x in range(n)]
C = [0 for x in range(max(A) + 1)]

for a in A[1:]:
    C[a] += 1

for i in range(1, max(A) + 1): # 累加和
    C[i] += C[i - 1]
    
for j in range(1, n + 1):
    B[C[A[j]]-1] = A[j]
    C[A[j]] -= 1

print(" ".join(map(str, B)))
