#16D8101014F 久留米 竜之介 Utyan0604 python3
def insertionsort(n,A):
	for i in range(n):
		t=A[i]
		j=i-1
		while j>=0 and A[j] > t:
			A[j+1]=A[j]
			j-=1
			A[j+1]=t
			
			
	
		for k in range(n):
			if k<n-1:
				print(A[k],end=" ")
			else:
				print(A[k])
			
n=int(input())
A=list(map(int, input().split()))

insertionsort(n,A)


