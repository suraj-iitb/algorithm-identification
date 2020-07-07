n = int(input())
A = [int(input()) for _ in range(n)]

# 間隔gを指定した挿入ソート
def insertSort(A, g):
	n = len(A)
	global cnt
	for i in range(g, n):
		v = A[i]
		j = i - g
		while j >= 0 and A[j] > v:
			A[j + g] = A[j]
			j -= g
			cnt += 1
		A[j + g] = v
	return 0

def shellSort(A):
	n = len(A)
	G = []
	# G = {1, 4, 13, 40, 121, 364,...}
	h = 1
	while h <= n:
		G.append(h)
		h = 3 * h + 1
	for i in range(len(G) - 1, -1, -1):
		insertSort(A, G[i])
	return G

cnt = 0
G = shellSort(A)
print(len(G))
print(*G[::-1])
print(cnt)
for v in A: print(v)
