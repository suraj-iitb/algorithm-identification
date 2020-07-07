def listprint(lists):
	global N
	count = 0
	for i in lists:
		count += 1
		if count < N:
			print(i, end = ' ')
		if count == N:
			print(i)

if __name__ == '__main__':
	N = int(input())
	l = input().split()

	for i in range(N):
		l[i] = int(l[i])

	listprint(l)

	for i in range(1, N):
		v = l[i]
		j = i - 1

		while j >= 0 and l[j] > v:
			l[j + 1] = l[j]
			j -= 1

		l[j + 1] = v
		listprint(l)
