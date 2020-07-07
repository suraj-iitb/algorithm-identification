length = int(input())
raw_list = input().split()
for i in range(length):
	raw_list[i] = int(raw_list[i])
for i in range(length):
	key = raw_list[i]
	j = i - 1
	while j >= 0 and raw_list[j] > key:
		raw_list[j+1] = raw_list[j]
		j -= 1
	raw_list[j+1] = key
	for k in range(length):
		if k-length+1:
			print(raw_list[k], end=' ')
		else:
			print(raw_list[k])
