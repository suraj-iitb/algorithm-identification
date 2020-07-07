def selection_sort(A, n):
	count = 0

	for i in range(n-1):
		minj = i
		for j in range(i, n):
			if A[j] < A[minj]:
				minj = j

		if i != minj:
			A[i], A[minj] = A[minj], A[i]
			count += 1

	print(' '.join(map(str, A)))
	print(count)

if __name__ == '__main__':
	n = int(input())
	A = list(map(int, input().split()))

	selection_sort(A, n)
