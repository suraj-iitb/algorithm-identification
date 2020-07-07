def test():

	n = int(input())
	A = list(map(int,input().split()))

	swap_count = 0
	for i in range(n):
		for j in range(n-1,i,-1):
			if A[j] < A[j-1]:
				swap_count += 1
				tmp = A[j]
				A[j] = A[j-1]
				A[j-1] = tmp

	for i in range(n-1):
		print(f"{A[i]} ",end = '')
	print(f"{A[n-1]}")
	print(swap_count)


if __name__ == "__main__":
	test()

