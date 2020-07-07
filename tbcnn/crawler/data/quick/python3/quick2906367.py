def partition(num_list, start, end):
    split = start -1
    x = int(num_list[end][1])
    for i in range(start, end):
        if int(num_list[i][1]) <= x:
            split += 1
            num_list[split], num_list[i] = num_list[i], num_list[split]
    num_list[split+1], num_list[end] = num_list[end], num_list[split+1]
    return split+1

def quickSort(num_list, start, end):
    if start < end:
        q = partition(num_list, start, end)
        quickSort(num_list, start, q-1)
        quickSort(num_list, q+1, end)

import sys, copy
n = int(input())
input_list = [sys.stdin.readline().rstrip().split() for i in range(n)]
check_list = copy.deepcopy(input_list)
quickSort(input_list, 0, n-1)
for i in range(n-1):
    if input_list[i][1] == input_list[i+1][1]:
        if check_list.index(input_list[i]) > check_list.index(input_list[i+1]):
            print('Not stable')
            break
else:
    print('Stable')
for i in input_list:
    print('{} {}'.format(i[0], i[1]))
