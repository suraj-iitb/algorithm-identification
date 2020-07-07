n=int(input())
a=list(map(int,input().split()))
print(' '.join(list(map(str,a))))
for i in range(1,n):
	v=a[i]
	j=i-1
	while j>=0 and a[j]>v:
		a[j+1]=a[j]
		a[j]=v
		j-=1
	print(' '.join(list(map(str,a))))
