n = int(input())
lst = list(map(int,input().split()))
flag = 1
count = 0
while flag:
    flag = 0
    for i in range(n-1,0,-1):
        if lst[i] < lst[i-1]:
            lst[i],lst[i-1] = lst[i-1],lst[i]
            flag = 1
            count = count + 1
tmp_lst = map(str,lst)
print(' '.join(tmp_lst))
print(count)

