n = int(input())
l = []
for i in map(int, input().split()):
    l.append(i)

'''
n = 10
l = [9,5,10,3,6,7,4,1,2,8]
'''

start_index = 0
swap_cnt = 0

for j in range(start_index, n):
    if len(l[start_index:n]) == 1:
        break
    else:
        tmp = l[start_index]
        min_value = l[start_index]
        min_index = start_index

        for idx in range(start_index,n):
            if min_value > l[idx]:
                min_value = l[idx]
                min_index = idx

        l[start_index] = min_value
        l[min_index] = tmp

        if min_value != tmp:
            swap_cnt += 1

        start_index += 1

print(' '.join(map(str,l)))
print(swap_cnt)
