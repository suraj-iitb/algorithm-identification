n = int(input())
A =[int(input()) for i in range(n)]

def insertion(A,n,g):
	global cnt
	for i in range(g,n):
		v=A[i]
		j=i-g
		while j >= 0 and A[j]>v:
			A[j+g]=A[j]
			j=j-g
			cnt+=1
		A[j+g]=v

cnt=0
g=[]
h=1
while h<=n:
	g.append(h)
	h=h*3+1
g=g[::-1]

print(len(g))
for i in g:
	insertion(A,n,i)
	if i ==1:
		print(i)
	else:	
		print(i,end=' ')
print(cnt)
for i in A:
	print(i)

