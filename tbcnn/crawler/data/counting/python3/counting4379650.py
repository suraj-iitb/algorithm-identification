n = int(input())
A = list(map(int,input().split()))

max = 10000

C = [0]*(max+1)
B = []

for i in range(n):
    C[A[i]]  += 1

for  j in range(len(C)):
    while C[j] != 0:
        B.append(str(j))
        C[j] -= 1

print(" ".join(B))

