n = int(input())
list1 =[int(i) for i in input().split()]
count=0
for i in range(n):
	for j in range(n-1,i,-1):
		if list1[j] < list1[j-1]:
			list1[j],list1[j-1]=list1[j-1],list1[j]
			count+=1
print(' '.join(list(map(str,list1))))
print(count)
