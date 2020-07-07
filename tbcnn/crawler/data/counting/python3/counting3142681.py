n = int(input())
A = list(map(int, input().split()))
B = [0 for i in range(n)]
C = [0 for i in range(max(A)+1)]
for i in A:
    C[i]+=1
for i in range(1, len(C)):
    C[i]+=C[i-1]
for i in range(0, n):
    B[C[A[i]]-1] = A[i]
    C[A[i]]-=1
print(" ".join(map(str, B)))
