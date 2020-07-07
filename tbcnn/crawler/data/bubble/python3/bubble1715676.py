def bubbleSort(R, N):
	flag = True
	cnt = 0
	while flag == True:
		flag = False
		for j in range(N - 1, 0, -1):
			if R[j] < R[j - 1]:
				tmp = R[j]
				R[j] = R[j - 1]
				R[j - 1] = tmp
				cnt = cnt + 1
				flag = 1
	print(" ".join(map(str, R)))
	return cnt

if __name__ == '__main__':
	n = int(input())
	A = list(map(int, input().split()))
	ans = bubbleSort(A, n)
	print(ans)
