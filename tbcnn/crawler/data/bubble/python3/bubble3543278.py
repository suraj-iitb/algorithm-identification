n=int(input())
cnt=0
num=list(map(int,input().split()))
for j in range(len(num)-1):
	for i in range(len(num)-1,0,-1):
		if num[i]<num[i-1]:
			num[i],num[i-1]=num[i-1],num[i]
			cnt+=1
print(' '.join(list(map(str,num))))
print(cnt)
