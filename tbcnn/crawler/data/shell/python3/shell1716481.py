def insertionSort(A, n, g):
	global cnt

	for i in range(g, n):
		v = A[i]
		j = i - g
		while j >= 0 and A[j] > v:
			A[j + g] = A[j]
			j = j - g
			cnt = cnt + 1
		A[j + g] = v

def shellSort(A, n):
	global m
	global G

	h = 1
	while (True):
		if h > n:
			break
		G.append(h)
		h = 3 * h + 1

	m = len(G)
	G.reverse()

	for i in range(m):
		insertionSort(A, n, G[i])

if __name__ == '__main__':
	N = int(input())
	R = [int(input()) for i in range(N)]

	cnt = 0
	G = []
	m = 0

	shellSort(R, N)

	print(m)
	print(" ".join(map(str, G)))
	print(cnt)
	for i in range(N):
		print(R[i])
