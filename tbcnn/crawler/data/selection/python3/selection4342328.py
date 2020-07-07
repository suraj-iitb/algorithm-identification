def selection_sort(lst):
    cnt = 0
    for i in range(len(lst)-1):
        minj = i
        for j in range(i+1, len(lst)):
            if lst[j] < lst[minj]:
                minj = j
        if lst[i] > lst[minj]:
            lst[i], lst[minj] = lst[minj], lst[i]
            cnt += 1
    return cnt

n = int(input())
lst = list(map(int, input().split()))
cnt = selection_sort(lst)
print(*lst)
print(cnt)
