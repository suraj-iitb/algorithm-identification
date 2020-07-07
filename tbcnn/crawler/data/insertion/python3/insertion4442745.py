n = int(input())  # 6
a = list(map(int, input().split()))  # [1, 4, 3, 6, 2, 5]
print(' '.join([str(n) for n in a]))

for i in range(1, len(a)):
	j = a[i]
	for k in range(i - 1, -1, -1):
		if a[k] > j:
			a[k + 1] = a[k]
			a[k] = j
	print(' '.join([str(n) for n in a]))

