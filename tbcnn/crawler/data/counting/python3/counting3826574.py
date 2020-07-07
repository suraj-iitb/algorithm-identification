n=int(input())
A=list(map(int,input().split()))
B=[0]*n
MA=max(A)
c=[0]*(MA+1)
for i in range(n):
	c[A[i]]+=1
for i in range(1,MA+1):
	c[i]+=c[i-1]
for j in range(n-1,-1,-1):
	# print(B)
	B[c[A[j]]-1]=A[j]
	c[A[j]]-=1

print(*B)

