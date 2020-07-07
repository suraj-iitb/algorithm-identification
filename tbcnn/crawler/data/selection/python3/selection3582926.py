if __name__ == '__main__':
	n = int(input())
	num = [int(i) for i in input().split()]
	count=0
	for i in range(n):
		mini = i
		for j in range(i,n):
			if num[j] < num[mini]:
				mini = j
		num[i],num[mini] = num[mini],num[i]
		if i != mini:
			count += 1
	for i in range(n):
		if i != n-1:
			print("%d" % (num[i]),end=" ")
		else:
			print("%d" % (num[i]))
	print(count)
