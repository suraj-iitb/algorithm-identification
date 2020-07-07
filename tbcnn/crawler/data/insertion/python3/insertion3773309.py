def sort(a, n):
	print(" ".join(map(str, a)))
	for i in range(1, N):
		v = a[i]
		j = i - 1
		while 0 <= j and v < a[j]:
			a[j + 1] = a[j]
			j -= 1
		a[j + 1] = v
		print(" ".join(map(str, a)))

N = int(input())
A = list(map(int, input().split()))

sort(A, N)

