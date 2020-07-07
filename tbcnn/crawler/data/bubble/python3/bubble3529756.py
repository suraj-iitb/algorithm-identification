num = int(input())
A = list(map(int,input().split(" ")))
chg = 0
for i in range(num):
	for j in range(num-1,i,-1):
		if A[j] < A[j-1]:
			A[j],A[j-1] = A[j-1],A[j]
			chg += 1
print(*A)
print(chg)

