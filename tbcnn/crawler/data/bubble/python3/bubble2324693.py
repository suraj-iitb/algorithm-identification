def bubble_sort(A, n):
	flag = 1
	i = 0
	count = 0

	while flag:
		flag = 0
		for j in range(n-1, i, -1):
			if A[j] < A[j-1]:
				A[j], A[j-1] = A[j-1], A[j]
				flag = 1
				count += 1

		i += 1
	
	print(' '.join(map(str, A)))
	print(count)


if __name__ == '__main__':
	n = int(input())
	A = list(map(int, input().split()))

	bubble_sort(A, n)
