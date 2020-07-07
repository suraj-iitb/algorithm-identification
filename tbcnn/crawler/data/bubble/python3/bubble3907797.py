def bubblesort(A, N):
	flag = 1
	count = 0
	while flag:
		flag = 0
		for j in range(N-1,0,-1):
			if A[j] < A[j-1]:
				A[j], A[j-1] = A[j-1], A[j]
				flag = 1
				count += 1
	print(*A)
	print(count)


if __name__ == "__main__":
	n = int(input())
	a = list(map(int, input().split()))
	bubblesort(a, n)
