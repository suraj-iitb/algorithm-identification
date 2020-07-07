def insertionSort(A, N):
	print(*A)
	for i in range(1, N):
		value = A[i]
		j = i - 1
		while j >= 0 and A[j] > value:
			A[j + 1] = A[j]
			j -= 1
		A[j + 1] = value
		print(*A)

if __name__ == "__main__":
	n = int(input())
	a = list(map(int, input().split()))
	insertionSort(a, n)
