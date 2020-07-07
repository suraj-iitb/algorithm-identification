import sys
def print_arr(arr):
	for i in range(len(arr)):
		sys.stdout.write(str(arr[i]))
		if i != len(arr) - 1:
			sys.stdout.write(' ')
	print()

n = int(input())
arr = list(map(int, input().split()))

for i in range(n):
	key = arr[i]
	j = i - 1
	while j >= 0 and arr[j] > key:
		arr[j + 1] = arr[j]
		j -= 1
	arr[j + 1] = key
	print_arr(arr)

