n = int(input())
data = [int(s) for s in input().split()]

change = 0
flag = True
while flag:
	flag = False
	for idx in range(1,n):
		if data[idx-1] > data[idx]:
			data[idx-1],data[idx] = data[idx],data[idx-1]
			flag = True
			change += 1

print(' '.join([str(d) for d in data]))
print(change)
