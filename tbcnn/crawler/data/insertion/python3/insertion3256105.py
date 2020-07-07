def main():
	n = int(input())
	a = list(map(int, input().split()))
	printlist(a)
	insertionSort(a, n)

def insertionSort(a, n):
	for i in range(1,n):
		v = a[i]
		j = i - 1
		while j >= 0 and a[j] > v:
			a[j + 1] = a[j]
			j -= 1
		a[j+1] = v
		printlist(a)

def printlist(a):
	values = map(str, a)
	print(' '.join(values))

main()
