def bubble_sort(array):
	N = len(array)
	count = 0
	
	for i in range(N - 1):
		flag = 0
		
		for j in range(N - 1, i, -1):
			if array[j - 1] > array[j]:
				array[j - 1], array[j] = array[j], array[j - 1]
				count += 1
				flag = 1
				
		if flag == 0:
			break
	
	return array, count
	
n = int(input())
array = [int(i) for i in input().split()]
result = bubble_sort(array)
print(*result[0])
print(result[1])
