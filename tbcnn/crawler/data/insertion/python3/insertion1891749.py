def ins(A,N):
	for i in range(N):
		v=A[i]
		j=i-1
		while j>=0 and A[j]>v:
			A[j+1]=A[j]
			j-=1
		A[j+1]=v
		for k in range(len(A)):
			if k==len(A)-1:
				print(A[k])
			else:
				print(A[k],end=" ")
N=int(input())
A=list(map(int,input().split(" ")))
ins(A,N)
