N = int(input())
A =list(map(int,input().split()))
L = [str(a) for a in A]
B = " ".join(L)
print(B)
for i in range(1,N):
	v = A[i]
	j = i -1
	while j>= 0 and A[j] >v:
		A[j+1] = A[j]
		j -= 1
	A[j+1] = v
	L = [str(a) for a in A]
	B = " ".join(L)
	print(B)
