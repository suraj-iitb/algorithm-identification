n=int(input())
a=list(map(int,input().split()))
k=max(a)
b=[0]*(n)
def Count(A, B, k):
	C=[0]*(k+1)
	for j in range(n):
		C[A[j]]+=1
	for i in range(1,k+1):
		C[i]+=C[i-1]
	for i in range(n-1,-1,-1):
		B[C[A[i]]-1]=A[i]
		C[A[i]]-=1
Count(a,b,k)
print(*b)
