N = int(input())

num_list = list(map(int,input().split()))

swap_count = 0

for i in range(len(num_list)-1):
    for k in range(len(num_list)-1,i,-1):
        if num_list[k] < num_list[k-1]:
            num_list[k],num_list[k-1] = num_list[k-1],num_list[k]
            swap_count += 1

print(' '.join(map(str,num_list)))
print("%d"%(swap_count))
