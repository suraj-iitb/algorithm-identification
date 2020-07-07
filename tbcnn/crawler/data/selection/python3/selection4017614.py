n=int(input())
a=list(map(int,input().split()))
ans=0
for i in range(n):
	mini=i
	for j in range(i,n):
		if a[j]<a[mini]:
			mini=j
	if a[i]>a[mini]:
		ans+=1
	a[i],a[mini]=a[mini],a[i]
print(*a)
print(ans)
