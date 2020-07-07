dummy = input()

s_list = list(map(int,input().split()))

#print(s_list)

count = 0
if len(s_list) == 1:
    for i,row in enumerate(s_list):
        if i == 0:
            print(row,end='')
        else:
            print('',row,end='')
    print()
    print(count)

else:
    for i in range(len(s_list)-1):

        min_i = i

        for j in range(i,len(s_list)):

            if s_list[j] < s_list[min_i]:
                min_i = j

        if s_list[i] != s_list[min_i]:
            count += 1
            min_num = s_list[min_i]

            s_list[min_i] = s_list[i]
            s_list[i]     = min_num

    for i,row in enumerate(s_list):
        if i == 0:
            print(row,end='')
        else:
            print('',row,end='')
    print()
    print(count)

    

        
