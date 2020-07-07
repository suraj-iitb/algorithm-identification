def print_arr(arr):
	arr_str = ''
	for i in range(len(arr)):
		arr_str += str(arr[i])
		if i != len(arr) - 1:
			arr_str += ' '
	print(arr_str)

n = int(input())
arr = list(map(int, input().split()))

swap_count = 0
for i in range(n):
	mini = i
	for j in range(i, n):
		if arr[j] < arr[mini]:
			mini = j
	if mini != i:
		temp = arr[i]
		arr[i] = arr[mini]
		arr[mini] = temp
		swap_count += 1

print_arr(arr)
print(swap_count)

