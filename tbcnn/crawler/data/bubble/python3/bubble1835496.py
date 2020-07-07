N = int(input())
a = [int(x) for x in input().split()]
def bubbleSort(A, N):
	flag = 1
	count = 0
	while flag:
		flag = 0
		for j in reversed(range(1,N)):
			if A[j] < A[j-1]:
				tmp = A[j]
				A[j] = A[j-1]
				A[j-1] = tmp
				flag = 1
				count += 1
	return A,count
ans,c = bubbleSort(a,N)
print(*ans)
print(c)
