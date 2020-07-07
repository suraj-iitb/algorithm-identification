n = int(input())
A = list(map(int, input().split()))
for j in range(n):
	d = A[j]
	i = j - 1
	while i >= 0 and A[i] > d:
		A[i+1] = A[i]
		i -= 1
	A[i+1] = d
	for i in range(n):
		if i:
			print(" ", end="")
		print(A[i], end="")
	print()

