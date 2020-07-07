#http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A

num = int(input())

A = list(map(int, input().split()))
print(" ".join(list(map(str,A))))

for i in list(range(1, len(A))):
	v = A[i]
	j = i - 1
	while j >= 0 and A[j] > v:
		A[j+1] = A[j]
		j -= 1
	A[j+1] = v
	print(" ".join(list(map(str,A))))
