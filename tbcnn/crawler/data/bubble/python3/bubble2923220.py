import sys

def print_arr(arr):
	for i in range(len(arr)):
		sys.stdout.write(str(arr[i]))
		if i != len(arr) - 1:
			sys.stdout.write(' ')
	print()

n = int(input())
arr = list(map(int, input().split()))

count = 0
for i in range(n):
	for j in range(n - 1, i, -1):
		if arr[j] < arr[j-1]:
			temp = arr[j]
			arr[j] = arr[j-1]
			arr[j-1] = temp
			count += 1

print_arr(arr)
print(count)
