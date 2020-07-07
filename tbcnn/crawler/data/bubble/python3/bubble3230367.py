def bubble_sort(num_list):
    cnt = 0
    flag = 1

    while flag:
        flag = 0
        for i in range(len(num_list)-1,0,-1):
            if num_list[i] < num_list[i-1]:
                num_list[i],num_list[i-1] = num_list[i-1],num_list[i]
                cnt += 1
                flag = 1
    return cnt

n = input()
num_list = list(map(int,input().split()))

ans = bubble_sort(num_list)
ans_list = [str(i) for i in num_list]
print(' '.join(ans_list))
print(ans)
