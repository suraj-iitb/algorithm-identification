def insertionSort(A, n, g, cnt):
	for i in range(g, n):
		v = A[i]
		j = i - g
		while (j >= 0) and (A[j] > v):
			A[j+g] = A[j]
			j = j - g
			cnt += 1
		A[j+g] = v
	return cnt

def shellSort(A, n, m, G):
	cnt = 0
	for i in range(m):
		cnt = insertionSort(A, n, G[i], cnt)
	return cnt

n = int(input())
A = []
for i in range(n):
	A.append(int(input()))

h = 1
p = 1
G = []

if n < 2:
	G = [1]
	p = 2
else:
	while h < n: 
		G.append(h)
		h = 3 ** p + h
		p += 1

G.reverse()
cnt = shellSort(A, n, p - 1, G)
print(p - 1)
print(" ".join(map(str, G)))
print(cnt)
for i in range(n):
	print(A[i])
