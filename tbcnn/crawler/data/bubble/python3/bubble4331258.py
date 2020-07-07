n = int(input())
#A = [int(input()) for i in range(n)]
L = [int(i) for i in input().split()]


def bubbleSort(A,N):
	i = 0
	cnt = 0
	flag = 1
	while flag:
		flag = 0
		for j in reversed(range(i+1,N)):
			if A[j] < A[j-1]:
				key = A[j-1]
				A[j-1] = A[j]
				A[j] = key
				flag = 1
				cnt += 1
		i += 1
	return cnt

cnt = bubbleSort(L,n)

for item in range(len(L)):
	if item == len(L)-1:
		print(L[item])
	else:
		print(L[item],end=" ")

print(cnt)
