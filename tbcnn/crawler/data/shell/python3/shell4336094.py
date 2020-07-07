import copy 
N = int(input())
#*L, = map(str, input().split())
L = [int(input()) for i in range(N)]
#*L, = input().split()

#A1 = copy.copy(L)
#A2 = copy.copy(L)
#G = []
G = []
cnt = 0

def insertion_sort(A,n,g):
	global cnt
	for i in range(g,n):
		v = A[i]
		j = i - g
		while j>= 0 and A[j] > v:
			A[j+g] = A[j]
			j = j - g
			cnt += 1
		A[j+g] = v


def shell_sort(A,n):
	h = 1
	while True:
		if h > n:
			break
		G.append(h)
		h = 3*h + 1
		
	for i in reversed(range(len(G))):
		insertion_sort(A,n,G[i])

shell_sort(L,N)
print(len(G))
G = G[::-1]
print(*G)
print(cnt)
for i in L:
	print(i)




