N = int(input())
A = [int(elem) for elem in input().split()]

def insertion_sort(A):
	for i in range(1,len(A)):
		for elem in A[:-1]:
			print(elem, end=' ')
		print(A[-1])
		v = A[i]
		j = i - 1
		while j >= 0 and A[j] > v:
			A[j + 1] = A[j]
			j -= 1
		A[j + 1] = v
	for elem in A[:-1]:
		print(elem, end=' ')
	print(A[-1])

insertion_sort(A)
