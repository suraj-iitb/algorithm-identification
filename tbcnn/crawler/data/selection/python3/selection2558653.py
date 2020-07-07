def selectionsort(A, N):
	count = 0
	for i in range(N):
		minj = i
		for j in range(i, N):
			if A[j] < A[minj]:
				minj = j
		A[i], A[minj] = A[minj], A[i]
		if (A[i] != A[minj]):
			count += 1
	return count

def main():
	n = int(input())
	data = list(map(int, input().split()))

	c = selectionsort(data, n)
	print(*data)
	print(c)

if __name__ == "__main__":
	main()
