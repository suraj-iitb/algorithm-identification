def selectsort(A):
	t=0
	for i in range(0,len(A)):
		mini=i
		for j in range(i, len(A)):
			if A[j]<A[mini]:
				mini=j
		if i!=mini:
			temp=A[i]
			A[i]=A[mini]
			A[mini]=temp
			t+=1
	return t		

input()
input=input()
A=[int(s) for s in input.split(' ')]
t=selectsort(A)
print (' '.join(map(str,A)))
print(t)
