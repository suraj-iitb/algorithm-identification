n = int(input())
a = [int(i) for i in input().split()]
change = 0
for i in range(n):
	u = n-1
	while u > i:
		if a[u-1] > a[u]:
			a[u-1], a[u] = a[u], a[u-1]
			change += 1
		u -= 1
print(*a)
print(change)
