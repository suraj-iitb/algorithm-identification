n=int(input())
s=input().split(' ')
m=0

for i in range(n):
	minj=i
	for j in range(i,n):
		if int(s[j])<int(s[minj]):
			minj=j
	if i!=minj:
		a=s[minj]
		s[minj]=s[i]
		s[i]=a
		m+=1
			
print(' '.join(s))
print(m)
