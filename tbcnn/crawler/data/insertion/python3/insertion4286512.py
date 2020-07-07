n=int(input())
table=list(map(int,input().split()))

def insertsort(a,n):
	for i in range(n):
		v=a[i]
		j=i-1
		while j>=0 and a[j]>v:
			a[j+1]=a[j]
			j-=1
		a[j+1]=v
		print(*a)

insertsort(table,n)
