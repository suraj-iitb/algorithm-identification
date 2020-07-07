N = int(input())
A = [int(i) for i in input().split()]
cnt =0
for i in range(N):
	minj = i
	for j in range(i,N):
		if A[j]<A[minj]:
			minj = j
	if minj != i:
		cnt += 1
	v = A[i]
	A[i] = A[minj]
	A[minj] = v

print(" ".join(map(str,A)))
print(cnt)
