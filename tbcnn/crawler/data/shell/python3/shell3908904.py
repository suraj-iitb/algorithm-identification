from typing import List

def insertionSort(A: List[int], n: int, g: int) -> None:
	global cnt
	for i in range(g, n):
		value = A[i]
		j = i - g
		while j >= 0 and A[j] > value:
			A[j + g] = A[j]
			j -= g
			cnt += 1
		A[j + g] = value


def shellSort(A: List[int], n: int) -> None:
	G: List[int] = []
	h = 1
	while (h <= n):
		G.append(h)
		h = 3 * h + 1
	G.reverse()
	for i in range(len(G)):
		insertionSort(A, n, G[i])

	print(len(G))
	print(*G)
	

if __name__ == "__main__":
	cnt = 0
	n = int(input())
	a = []
	for _ in range(n):
		a.append(int(input()))
	shellSort(a, n)
	print(cnt)
	for i in range(len(a)):
		print(a[i])
