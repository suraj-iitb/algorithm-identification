N = int(input())
a = [int(x) for x in input().split()]
def selectionSort(A, N):
	count = 0
	for i in range(0,N):
		minj = i
		for j in range(i,N):
			if A[minj] > A[j]:
				minj = j
		if i != minj:
			tmp = A[minj]
			A[minj] = A[i]
			A[i] = tmp
			count += 1
	return A,count
ans,c = selectionSort(a,N)
print(*ans)
print(c)
