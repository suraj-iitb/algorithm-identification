import sys
import math

def insertion_sort(A, n, g):
	cnt = 0
	for i in range(g, n):
		v = A[i]
		j = i - g
		
		while j >= 0 and A[j] > v:
			A[j + g] = A[j]
			j = j - g
			cnt += 1

		A[j + g] = v

	return cnt

def shell_sort(A, n):
	cnt = 0
	m = math.floor(math.log(2 * n + 1) / math.log(3))
	print(m)

	G = [0 for i in range(m)]	
	G[0] = 1
	for i in range(1, m):
		G[i] = 3 * G[i - 1] + 1

	G.reverse()
	print(G[0], end = "")
	for i in range(1, m):
		print(" " + str(G[i]), end = "")

	print("")
	for i in range(m):
		cnt += insertion_sort(A, n, G[i])

	print(cnt)
	
	for i in range(n):
		print(A[i])


#fin = open("test.txt", "r")
fin = sys.stdin

n = int(fin.readline())
A = [0 for i in range(n)]

for i in range(n):
	A[i] = int(fin.readline())

shell_sort(A, n)
