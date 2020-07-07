
def bubblesort(a, n):
	flag = 1
	count = 0
	while flag:
		flag = 0
		for j in range(n-1, 0, -1):
			if a[j] < a[j-1]:
				count += 1
				a[j], a[j-1] = a[j-1], a[j]
				flag = 1
	return count

def main():
	n = int(input())
	data = list(map(int, input().split()))

	c = bubblesort(data, n)
	print(*data)
	print(c)

if __name__ == "__main__":
	main()
