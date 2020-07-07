def bubble_sort(lst):
    cnt = 0
    flag = True
    while flag:
        flag = False
        for i in range(len(lst)-1):
            if lst[i] > lst[i+1]:
                lst[i], lst[i+1] = lst[i+1], lst[i]
                flag = True
                cnt += 1
    return cnt

n = int(input())
lst = list(map(int, input().split()))
cnt = bubble_sort(lst)
print(*lst)
print(cnt)
