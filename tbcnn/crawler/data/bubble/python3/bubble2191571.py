N = int(input())
A = list(map(int, input().split()))

flag = 1
counter = 0
while flag:
	flag = 0
	for i in reversed(range(1,N)):
		if A[i] < A[i-1]:
			A[i], A[i-1] = A[i-1], A[i]
			counter += 1
			flag = 1
print(" ".join(map(str, A)))
print(counter)
