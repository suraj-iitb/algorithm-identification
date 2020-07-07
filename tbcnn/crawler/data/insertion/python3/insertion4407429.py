num = int(input())
sort_list = list(map(int,input().split()))

for i in range(1,num):
    for n, sl in enumerate(sort_list):
        if n != num - 1:
            print('{} '.format(sl),end='')
        else:
            print('{}'.format(sl))

    tmp = sort_list[i]
    j = i -1
    while j >= 0 and sort_list[j] >= tmp:
        buf = sort_list[j]
        del sort_list[j]
        sort_list.insert(j + 1, buf)
        j -= 1

for n, sl in enumerate(sort_list):
    if n != num - 1:
        print('{} '.format(sl),end='')
    else:
        print('{}'.format(sl))

