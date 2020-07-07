def test():

	n = int(input())
	A = list(map(int,input().split()))

	swap_count = 0
	for i in range(n):
		mini = i
		for j in range(i,n):
			if A[j] < A[mini]:
				mini = j
		tmp = A[i]
		A[i] = A[mini]
		A[mini] = tmp
		if i != mini:
			swap_count += 1

	for i in range(n-1):
		print(f"{A[i]} ",end = '')
	print(f"{A[n-1]}")
	print(swap_count)


if __name__ == "__main__":
	test()
