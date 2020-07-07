def selection_sort(A, N):
	cnt = 0
	for i in range(N):
		minj = i
		for j in range(i, N):
			if A[j] < A[minj]:
				minj = j
		A[i], A[minj] = A[minj], A[i]
		if minj!=i:
			cnt += 1

	return A, cnt

N = int(input())
A = list(map(int, input().split()))

A, cnt = selection_sort(A, N)
print(' '.join(map(str, A)))
print(cnt)
