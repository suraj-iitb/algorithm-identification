n=int(input())
A=[0]*(n+1)
B=[0]*(n+1)
i=0
mx=(1<<30)*-1
for v in list(map(int,input().split())):
	A[i+1] = v
	mx=max(mx,A[i+1])
	i+=1	

C=[0]*(mx+1)
for i in range(n):
	C[A[i+1]]+=1
for i in range(1,mx+1):
	C[i] += C[i-1]
for i in range(n,0,-1):
	B[C[A[i]]] = A[i]
	C[A[i]]-=1

st=str(B[1])
for i in range(2,n+1):
	st += ' ' + str(B[i])
print(st)

