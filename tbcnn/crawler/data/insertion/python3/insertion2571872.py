a = []
def outputList(a):
	for i in range(len(a)):
		if i != len(a)-1:
			print("%d"%a[i],end=' ')
		else:
			print("%d"%a[i],end='\n')

n = int(input().strip())
for i in input().split():
	a.append(int(i))
	if len(a)==n:
		break
for i in range(1,len(a)):
	outputList(a)
	key = a[i]
	j = i - 1
	while j >= 0 and a[j] > key:
		a[j+1] = a[j]
		j -= 1
	a[j+1] = key
outputList(a)
