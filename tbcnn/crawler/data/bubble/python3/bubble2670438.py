def bubble(l):
	count = 0
	N = len(l)
	flag = 1

	while flag:
		flag = 0
		for j in range(N - 1, 1 - 1, -1):
			if l[j] < l[j - 1]:
				l[j], l[j - 1] = l[j - 1], l[j]
				flag = 1
				count += 1

	return l, count


if __name__ == '__main__':
	n = int(input())
	l = input().split()

	for i in range(n):
		l[i] = int(l[i])

	l, c = bubble(l)
	count = 0
	leng = len(l)
	for i in l:
		count += 1
		if count < leng:
			print(i, end =' ')
		else:
			print(i)
			print(c)

