if __name__ == '__main__':
	n = int(input())
	num = [int(i) for i in input().split()]
	
	# bubble sort
	flag = 1
	count = 0
	while flag != 0:
		flag = 0
		rev = list(range(1,n))
		rev.reverse()
		for j in rev:
			if num[j] < num[j-1]:
				tmp = num[j]
				num[j] = num[j-1]
				num[j-1] = tmp
				flag = 1
				count += 1
	for i in range(n):
		if i != n-1:
			print("%d" % (num[i]),end=" ")
		else:
			print("%d" % (num[i]))
	print(count)
