def test():

	n = int(input())
	A = list(map(int,input().split()))

	for k in range(n-1):
		print(f"{A[k]} ",end = '')
	print(f"{A[n-1]}")

	for i in range(1,n):
		
		key = A[i]
		j = i - 1
		while j >= 0 and A[j] > key:
			A[j+1] = A[j]
			j -= 1
		A[j+1] = key
		for k in range(n-1):
			print(f"{A[k]} ",end = '')
		print(f"{A[n-1]}")

if __name__ == "__main__":
	test()


