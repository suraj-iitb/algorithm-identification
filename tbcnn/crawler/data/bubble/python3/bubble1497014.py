N=int(input())

A=list(map(int,input().split()))

count=0
i=N-1

while i>0:
	j=0
	while j<i:
		if A[N-1-j]<A[N-2-j]:
			(A[N-1-j],A[N-2-j])=(A[N-2-j],A[N-1-j])
			count+=1
			#print(' '.join(map(str,A)))
		j+=1
	i-=1


print(' '.join(map(str,A)))
print(count)
