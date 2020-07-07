import sys
n = int(input())
A = [int(i) for i in sys.stdin.readlines()]
h = 0
G =[]
while n >= 3*h+1:
	G.append(3*h+1)
	h = 3*h+1
for i in range(len(G)//2):
	G[i],G[-1-i] =G[-1-i],G[i]
cnt = 0
m = len(G)
def c_function(A,g,n):
	c = 0	
	for i in range(g,n):
		v = A[i]
		j = i-g			
		while j >= 0 and 		A[j]>v:
			A[j+g] = A[j]
			j = j-g
			c +=1
		A[j+g]=v
	return c

for k in range(m):
	g = G[k]
	cnt += c_function(A,g,n)	

print(m)
print(" ".join(map(str,G)))
print(cnt)
for i in range(n):
	print(A[i])
