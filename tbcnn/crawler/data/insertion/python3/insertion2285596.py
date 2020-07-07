def print_list(ele_list):
    print(" ".join(map(str, ele_list)))

def insertion_sort(ele_list):
    len_ele_list = len(ele_list)
    print_list(ele_list)
    for i in range(1, len_ele_list):
        key = ele_list[i]
        j = i - 1
        while j >= 0 and ele_list[j] > key:
            ele_list[j+1] = ele_list[j]
            j -= 1
        ele_list[j+1] = key
        print_list(ele_list)

N = int(input())
ele_list = list(map(int, input().split()))

insertion_sort(ele_list)
