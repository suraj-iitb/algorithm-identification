def insertion_sort(num_list):
    print(' '.join(num_list))

    for i in range(1,len(num_list)):
        popped_num = num_list[i]
        j = i-1
        while j >= 0 and int(num_list[j]) > int(popped_num):
            num_list[j+1] = num_list[j]
            j -=1
        num_list[j+1] = popped_num
        print(' '.join(num_list))


n = input()
num_list = list(input().split())
insertion_sort(num_list)

