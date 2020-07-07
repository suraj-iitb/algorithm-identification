maxx = 2000001
maxnum = 10010

n=int(input())
A=[int(x) for x in input().split()]  

B = [0] * n
C = [0] * maxnum

for a in A:
	C[a] += 1


for i in range(1,len(C)):
	C[i] += C[i-1]

for j in reversed(range(0,len(A))):
	B[C[A[j]]-1] = A[j]
	C[A[j]] -= 1

print(*B)


