n = int(input())
a = [int(i) for i in input().split()]
change = 0
for i in range(n-1):
	minA = 1000
	doko = 0
	for u in range(i+1, n):
		if minA > a[u]:
			minA = a[u]
			doko = u
	if minA < a[i]:
		a[i], a[doko] = a[doko], a[i]
		change += 1
print(*a)
print(change)
