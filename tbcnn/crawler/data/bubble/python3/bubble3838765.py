N = int(input())
A = list(map(int,input().split()))

flag = 1 #逆の隣接要素が存在する
cnt = 0
while flag :
	flag = 0
	for j in reversed(range(1,N)):
		if A[j]<A[j-1]:
			v = A[j]
			A[j] = A[j-1]
			A[j-1] = v
			flag = 1
			cnt += 1
print(" ".join(list(map(str,A))
))
print(cnt)
