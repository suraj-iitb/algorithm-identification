n = int(input())
lst = list(map(int,input().split()))
count = 0
for i in range(0,n):
    flag = 0
    minj = i
    for j in range(i,n):
        if lst[j] < lst[minj]:
            minj = j
            flag = 1
    lst[i],lst[minj] = lst[minj],lst[i]
    if flag == 1:
        count = count + 1
tmp_lst = map(str,lst)
print(' '.join(tmp_lst))
print(count)
