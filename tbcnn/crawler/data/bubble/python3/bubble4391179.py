# Bubble Sort

n = int(input())
A = list(map(int, input().split()))

def bubbleSort(A):
	n = len(A)
	cnt = 0 # 要素の交換回数
	flag = 1
	while flag:
		flag = 0
		for j in range(n - 1, 0, -1):
			if A[j] < A[j - 1]:
				A[j], A[j - 1] = A[j - 1], A[j]
				flag = 1
				cnt += 1
	return A, cnt

res, cnt = bubbleSort(A)
print(*res)
print(cnt)
