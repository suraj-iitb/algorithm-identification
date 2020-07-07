def selectionSort(A, N):
	global cnt

	for i in range(N):
		minj = i
		for j in range(i, N):
			if A[j] < A[minj]:
				minj = j
		if i != minj:
			tmp = A[i]
			A[i] = A[minj]
			A[minj] = tmp
			cnt = cnt + 1 #

	return A

if __name__ == '__main__':
	n = int(input())
	R = list(map(int, input().split()))
	cnt = 0
	R = selectionSort(R, n)
	print(" ".join(map(str, R)))
	print(cnt)
