def insertionSort(data):
	for old in range(len(data)):
		new = old
		while new>0 and data[old]<data[max(0,new-1)]:
			new -= 1
		i = data.pop(old)
		data.insert(new,i)
		yield data

input()
data = [int(s) for s in input().split()]
[print(' '.join([str(i) for i in d])) for d in insertionSort(data)]
