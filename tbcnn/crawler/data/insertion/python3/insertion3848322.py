i=int(input())
n=list(map(int,input().split()))
print(' '.join(map(str, n)))
for k in range(1,i):
	target=n[k]
	hh=k-1
	while hh>=0 and n[hh]>target:
		n[hh+1]=n[hh]
		hh-=1
	n[hh+1]=target
	print(' '.join(map(str, n)))


