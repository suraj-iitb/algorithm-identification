
def bubble(a):
	ct=0
	for i in range(len(a)-1):
		for j in range(len(a)-1,i,-1):
			if a[j]<a[j-1]:
				t=a[j]
				a[j]=a[j-1]
				a[j-1]=t
				ct+=1
	return a,ct
n=int(input())
table=list(map(int,input().split()))
b,c=bubble(table)
print(*b)
print(c)
