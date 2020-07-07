n=int(input())
A=input().split()
print(' '.join(A))
for i in range(1,n):
	key=int(A[i])
	j=i-1
	while j>=0 and int(A[j])>key:
		A[j+1]=A[j]
		j-=1
		A[j+1]=str(key)
	print(' '.join(A))


