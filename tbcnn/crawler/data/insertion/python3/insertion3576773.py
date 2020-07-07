def print_array(data):
	for i in range(len(data)):
		if i != len(data)-1:
			print("%d" % data[i],end=" ")
		else:
			print("%d" % data[i])

if __name__ == '__main__':
	num = int(input())
	a = [int(i) for i in input().split()]
	for i in range(1,num):
		print_array(a)
		key = a[i]
		j = i - 1
		while j >= 0 and a[j] > key:
			a[j+1] = a[j]
			j -= 1
		a[j+1] = key
	print_array(a)
