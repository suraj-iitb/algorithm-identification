def selection(l):
	N = len(l)
	count = 0

	for i in range(N):
		minj = i

		for j in range(i, N):
			if l[j] < l[minj]:
				minj = j
		if i == minj:
			continue
		else:
			l[i], l[minj] = l[minj], l[i]
			count += 1

	return l, count




if __name__ == '__main__':
	n = int(input())
	l = input().split()

	for i in range(n):
		l[i] = int(l[i])

	l, c = selection(l)
	count = 0
	leng = len(l)
	for i in l:
		count += 1
		if count < leng:
			print(i, end =' ')
		else:
			print(i)
			print(c)

