N = int(input())
A = list(map(int, input().split()))

def sort(a):
	count = 0
	for n in range(len(a)):
		min_n = n
		for m in range(n, len(a)):
			if a[m] < a[min_n]:
				min_n = m
		if n != min_n:
			count += 1
			a[n], a[min_n] = a[min_n], a[n]
	return count

count = sort(A)
print(*A)
print(count)

