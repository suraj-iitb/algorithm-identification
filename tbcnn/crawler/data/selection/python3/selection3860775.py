def main(n):
	a = list(map(int,input().split()))
	ans = 0
	for i in range(n):
		minj = i
		for j in range(i, n):
			if a[j] < a[minj]:
				minj = j
		if minj == i:
			continue
		a[i], a[minj] = a[minj], a[i]
		ans += 1
	print(" ".join(map(str, a)))
	print(ans)

main(int(input()))
