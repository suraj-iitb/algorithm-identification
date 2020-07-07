def Print(numlist):
	for t in range(len(numlist)):
		print(numlist[t], end = '')
		if t != len(numlist) - 1:
			print(end = ' ')
	print()

n = eval(input())
numlist = [eval(item) for item in input().split()]
Print(numlist)
for i in range(1, n):
	tmp = numlist[i]
	for j in range(i, -1, -1):
		if tmp > numlist[j - 1]:
			break
		numlist[j] = numlist[j - 1]
	numlist[j] = tmp
	Print(numlist)
