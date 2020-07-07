#http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_B

x = int(input())
y = list(map(int,input().split()))
z = 0

for i in range(x):
	minj = i
	for j in range(i,x):
		if y[j] < y[minj]:
			minj = j
	if not i == minj:
		y[i], y[minj] = y[minj], y[i]
		z += 1

print(" ".join(list(map(str,y))))
print(z)
