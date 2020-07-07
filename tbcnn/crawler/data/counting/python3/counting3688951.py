n=int(input())
L=input().split( )
A=[int(L[i]) for i in range(n)]
k=10002
C=[]
for i in range(k):
    C += [0]
#print(C[:20])

for j  in range(n):
     C[A[j]]+=1
#print(C[:20])
B=[]

for j in range(k):
    for l in range(C[j]):
        B.append(j)

print(*B)

