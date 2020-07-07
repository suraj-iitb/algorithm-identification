def countingSort(A, B, k, n):
	C = [0] * (k + 1)

	# C[i]にiの出現数を記録する
	for j in range(n):
		C[A[j]] += 1
	
	# C[i]にi以下の数の出現数を記録する
	for i in range(1, k + 1):
		C[i] = C[i] + C[i - 1]

	for j in range(n - 1, -1, -1):
		B[C[A[j]] - 1] = A[j]
		C[A[j]] -= 1


if __name__ == "__main__":
	n = int(input())
	A = list(map(int, input().split()))
	k = max(A)
	B = [0] * n
	countingSort(A, B, k, n)
	print(' '.join(map(str, B)))

