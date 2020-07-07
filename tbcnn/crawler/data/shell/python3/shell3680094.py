def insert_sort(A,n,g):
	cnt = 0
	for i in range(g,n):
		key = A[i]
		j = i - g
		while j >= 0 and A[j] > key:
			A[j+g] = A[j]
			j -= g
			cnt+=1
		A[j+g] = key
	return cnt

def shell_sort(A,n):
	cnt = 0
	g = []
	tmp = 1
	while tmp <= -(-n//3):
		g.append(tmp)
		tmp = tmp*3 + 1
	g.reverse()
	m = len(g)
	print(m)
	print(*g)
	for i in range(m):
		cnt += insert_sort(A,n,g[i])
	print(cnt)

if __name__ == '__main__':
	n = int(input())
	A = []
	for i in range(n):
		A.append(int(input()))
	shell_sort(A,n)
	for i in A:
		print(i)
