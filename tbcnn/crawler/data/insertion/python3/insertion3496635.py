def show(A):
	for i in range(len(A)):
		if i != len(A) - 1:
			print(A[i], end=' ')
		else:
			print(A[i])

def insertionSort(n, A):
	for i in range(1,n):
		key = A[i]
		j = i - 1
		while (j >= 0 and A[j] > key):
			A[j+1] = A[j]
			j = j - 1
		A[j+1] = key
		show(A)
		
n = int(input())
nums = list(map(int, input().split()))
show(nums)
insertionSort(n, nums)
