def insertionSort(A, N, g):
    global cnt
    for i in range(g, N):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
            #print('cnt = ' + str(cnt))
        A[j+g] = v

N = int(input())
A = [int(input()) for i in range(N)]
cnt = 0
G = []
h = 1
while (True):
	if h > N:
		break
	G.append(h)
	h = 3 * h + 1
G.reverse()
m = len(G)
for i in range(m):
    insertionSort(A, N, G[i])
print(m)
print(*G)
print(cnt)
print(*A, sep='\n')
