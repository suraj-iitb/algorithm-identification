n = int(input())
a = list(map(int, input().split()))
flg = True
cnt = 0
while flg:
	flg = False
	for i in range(len(a) - 1, 0, -1):
		if a[i] < a[i - 1]:
			a[i - 1], a[i] = a[i], a[i - 1]
			cnt = cnt +1
			flg = True

print(' '.join([str(n) for n in a]))
print(cnt)
# for i in range(0, len(a)):
#	print('{0} {1}'.format(i, a[i]))

# for i in range(0,10):
#	print('{} '.format(i), end='')
# print()

# for i in range(10,0, -1):
#	print('{} '.format(i), end='')

