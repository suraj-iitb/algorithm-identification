def bubbleSort(a,n):
	cnt=0
	for i in range(n-1,0,-1):
		for j in range(i):
			if a[j]>a[j+1]:
				a[j],a[j+1]=a[j+1],a[j]
				cnt+=1
	return cnt	
	
n=int(input())
a=list(map(int,input().split()))
cnt=bubbleSort(a,n)
print(' '.join(map(str,a)))
print(cnt)
