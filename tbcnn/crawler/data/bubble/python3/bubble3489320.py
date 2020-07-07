def bubble_sort(A, N):
	count = 0
	flag = 1
	while flag:
		flag = 0
		for i in range(N-1, 0, -1):
			if A[i] < A[i-1]:
				temp = A[i]
				A[i] = A[i-1]
				A[i-1] = temp
				count += 1
				flag = 1

	return A, count

N = int(input())
A = list(map(int, input().split()))

A, count = bubble_sort(A, N)
print(' '.join(map(str, A)))
print(count)
