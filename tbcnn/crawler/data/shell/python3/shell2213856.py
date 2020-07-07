def InsertionSort(A, N, g, cnt):
	for i in range(g,N):
		v = A[i]
		j = i-g
		while j >= 0 and A[j] > v:
			A[j+g] = A[j]
			j -= g
			cnt += 1
		A[j+g] = v
	
	return(cnt, A)

N = int(input())
A = [int(input()) for j in range(N)]

cnt = 0
G=[]
G.append(1)

for i in range(100):
	g = 3 * G[i] + 1
	if g >= N:
		break
	else:
		G.append(g)

G.reverse()
m = len(G)
print(m)
print(" ".join(map(str, G)))

for i in range(m):
	cnt, A = InsertionSort(A, N, G[i], cnt)

print(cnt)
Ap = [print(A[i]) for i in range(N)]
