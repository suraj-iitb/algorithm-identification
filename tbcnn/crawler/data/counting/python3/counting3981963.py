n=int(input())
A=[int(i) for i in input().split()]

k=max(A)
C=[0]*(k+1)

for i in range(n):
    C[A[i]]+=1

for i in range(1,k+1):
    C[i] = C[i] + C[i-1]

B=[0]*(n+1)

for i in [n-i-1 for i in range(n)]:
    B[C[A[i]]] = A[i]
    C[A[i]]-=1
    

print(*B[1:])
