import sys

input_len = int(input())
l = input().split()
sort_line = [0 for i in range(input_len)]
for i in range(input_len):
	sort_line[i] = int(l[i])
	

for k in range(input_len):
	if (k > 0):
		sys.stdout.write(" ")
	sys.stdout.write(str(sort_line[k]))
print()

for i in range(1, input_len):
	v = sort_line[i]
	j = i - 1
	while (j >= 0 and v < sort_line[j]):
		sort_line[j+1] = sort_line[j]
		j -= 1
	sort_line[j + 1] = v

	for k in range(input_len):
		if (k > 0):
			sys.stdout.write(" ")
		sys.stdout.write(str(sort_line[k]))
	print()
