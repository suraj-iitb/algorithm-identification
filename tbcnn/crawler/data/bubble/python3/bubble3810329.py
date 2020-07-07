n = int(input())
A =[int(i) for i in input().split()]
count=0
for i in range(n):
	for j in range(n-1,i,-1):
		if A[j]<A[j-1]:
			A[j],A[j-1]=A[j-1],A[j]
			count+=1
print(' '.join(list(map(str,A))))
print(count)
