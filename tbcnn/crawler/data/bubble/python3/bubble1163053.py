n = int(input())
a = list(map(int,input().split()))
cnt = 0
for i in range(0,n):
	for j in range(i+1,n)[::-1]:
		if a[j]<a[j-1]:
			a[j],a[j-1] = a[j-1],a[j]
			cnt += 1
print(" ".join(map(str,a)))
print(cnt)
