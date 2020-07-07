n = input()
b = int(n) - 1

a = input().split()
nlist = [int(i) for i in a]

#calc func
for j in range(int(n)):
	if j != 0:
		for c2 in reversed(range(0,j)):
			if nlist[c2] > nlist[j]:
				stk = nlist[c2]
				nlist[c2] = nlist[j]
				nlist[j] = stk
				j = j - 1
				c2 = j - 1

#print func
	for i in range(int(b)):
		print(nlist[i], end=" ")

	print(nlist[b])


