n=int(input())
num=list(map(int,input().split()))
count=0
for i in range(0,n):
	minj=i
	a=0
	for j in range(i+1,n):
		if num[minj]>num[j]:
			minj=j
	if minj!=i:
		count+=1
	a=num[minj]
	num[minj]=num[i]
	num[i]=a
print(' '.join(list(map(str,num))))
print(count)
