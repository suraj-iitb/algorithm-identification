def main():
	n = int(input())
	r = [int(a) for a in input().split()]
	ct = bubbleSort(r, n)
	printlist(r)
	print(ct)

def bubbleSort(a , n):
	cnt = 0
	flag = True
	while flag:
		flag = False
		for i in range(1, n)[::-1]:
			if a[i] < a[i-1]:
				cnt += 1
				a[i], a[i-1] = a[i-1], a[i]
				flag = True
	return cnt


def printlist(a):
	values = map(str, a)
	print(' '.join(values))

main()
