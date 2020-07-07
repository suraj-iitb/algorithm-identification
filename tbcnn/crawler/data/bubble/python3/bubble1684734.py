n = int(input())
data = [int(i) for i in input().split(' ')]

def bubble_sort(raw_list):
    n_list = len(raw_list)
    n_swap = 0
    sorted_i = 1
    flag = True
    while flag:
        flag = False
        for j in reversed(range(sorted_i, n_list)):
            if raw_list[j] < raw_list[j-1]:
                raw_list[j-1], raw_list[j] = raw_list[j], raw_list[j-1]
                n_swap += 1
                flag = True
        sorted_i += 1
    print(' '.join([str(i) for i in raw_list]))
    print(n_swap)
        
bubble_sort(data)
