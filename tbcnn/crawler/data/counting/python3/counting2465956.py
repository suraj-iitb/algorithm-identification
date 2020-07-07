def counting_sort(A, B, k):
	C = [0 for i in range(k+1)]
	for a in A:
		C[a] += 1
	for i in range(1,k+1):
		C[i] += C[i-1]
	for a in A:
		B[C[a]-1] = a
		C[a] -= 1


if __name__ == '__main__':
	n = int(input())
	A = [int(s) for s in input().split()]
	B = A[:]
	counting_sort(A, B, max(A))
	print(*B)
