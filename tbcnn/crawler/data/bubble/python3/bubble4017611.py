n=int(input())
a=list(map(int,input().split()))
flag=True
cnt=0
for i in range(n):
	if not flag:
		break
	flag=False
	for j in range(n-1,i,-1):
		if a[j]<a[j-1]:
			a[j],a[j-1]=a[j-1],a[j]
			cnt+=1
			flag=True
print(*a)
print(cnt)
