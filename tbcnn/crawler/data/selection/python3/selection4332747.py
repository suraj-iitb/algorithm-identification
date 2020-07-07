n = int(input())
*L, = map(int, input().split())
#L = [int(i) for i in input().split()]

def SelectionSort(A,N):
	cnt = 0
	for i in range(N):
		minj = i
		for j in range(i,N):
			if A[j] < A[minj]:
				minj = j
		if A[i] > A[minj]:
			A[i], A[minj] = A[minj], A[i]
			cnt += 1
	return cnt

cnt = SelectionSort(L,n)

print(*L)
print(cnt)
