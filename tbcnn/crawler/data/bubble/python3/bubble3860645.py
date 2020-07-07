def main(n):
	a = list(map(int,input().split()))
	ans = 0
	flg = True
	while flg:
		flg = False
		for i in range(n-1, 0, -1):
			if a[i] < a[i-1]:
				a[i], a[i-1] = a[i-1], a[i]
				ans += 1
				flg = True
	print(" ".join(map(str, a)))
	print(ans)

main(int(input()))
