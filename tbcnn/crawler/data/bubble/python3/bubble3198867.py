x=int(input())
n=list(map(int,input().split()))
count=0
flag=0
while flag==0:
	flag=1
	a=0
	for i in range(1,len(n)):
		if n[i-1]>n[i]:
			a=n[i-1]
			n[i-1]=n[i]
			n[i]=a
			count+=1
			flag=0
print(' '.join(list(map(str,n))))
print(count)
	
		
		
