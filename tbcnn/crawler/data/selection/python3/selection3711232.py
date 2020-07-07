n= int(input())
a=list(map(int,input().split()))

c=0


for i in range(0,n):
	minj=i
	for j in range(i,n):
		if a[j] < a[minj]:
			minj=j
	if i != minj:
		c+=1
	a[i],a[minj]=a[minj],a[i]

print(*a)
print(c)

