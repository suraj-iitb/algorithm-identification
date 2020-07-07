def insertion_sort(A,N):
	prin(A)
	for i in range(1,N):
		v = A[i]
		j = i-1
		while j >= 0 and A[j] > v:
			A[j+1] = A[j]
			j -= 1
		A[j+1] = v
		prin(A)
def prin(A):
	print(' '.join(list(map(str, A))))
N = int(input())
A = [int(i) for i in input().split(' ')]
insertion_sort(A,N)
