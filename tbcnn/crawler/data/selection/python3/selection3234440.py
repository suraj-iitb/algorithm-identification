def selection_sort(num_list):
    cnt = 0

    for i in range(len(num_list)-1):
        min_idx = i
        for j in range(i,len(num_list)):
            if num_list[j] < num_list[min_idx]:
                min_idx = j
        if i != min_idx:
            num_list[i],num_list[min_idx] = num_list[min_idx],num_list[i]
            cnt += 1
    return cnt

n = int(input())
num_list = list(map(int,input().split()))
ans = selection_sort(num_list)
ans_list = [str(i) for i in num_list]

print(' '.join(ans_list))
print(ans)
