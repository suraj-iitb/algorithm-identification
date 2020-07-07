#http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A

x = int(input())
y = list(map(int,input().split()))
z = 0

flag = 1
while flag:
	flag = 0
	i = x - 1
	while i > 0:
		if y[i] < y[i - 1]:
			y[i], y[i - 1] = y[i - 1], y[i]
			flag = 1
			z += 1
		i -= 1

print(" ".join(list(map(str,y))))
print(z)
