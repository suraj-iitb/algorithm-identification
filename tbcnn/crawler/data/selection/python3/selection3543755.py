n=int(input())
cnt=0
num=list(map(int,input().split()))

for i in range(len(num)):
	min=i
	for j in range(i,len(num)):
		if num[j]<num[min]:
			min=j
	if num[i]>num[min]:
		num[i],num[min]=num[min],num[i]
		cnt+=1
print(' '.join(list(map(str,num))))
print(cnt)
	
				
			
			

