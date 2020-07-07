n = int(input())
num_list = list(map(int, input().split()))
# n = 6
# num_list = [5,6,4,2,1,3]

num_swap = 0
for i in range(n):
    index = -1
    mini = num_list[i]
    for j in range(i, n):
        if mini > num_list[j]:
            index = j            
            mini = num_list[j]
    if index > -1:
        num_swap += 1
        num_list[i], num_list[index] = num_list[index], num_list[i]
print(' '.join(map(str, num_list)))
print(num_swap)
