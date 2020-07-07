# completed
def print_list(ele_list):
    print(" ".join(map(str, ele_list)))

def bubble_sort(ele_list):
    len_ele_list = len(ele_list)
    num_swap = 0
    for i in range(0, len_ele_list):
       for j in range(len_ele_list-1, i, -1):
           if ele_list[j] < ele_list[j-1]:
               key = ele_list[j]
               ele_list[j] = ele_list[j-1]
               ele_list[j-1] = key
               num_swap += 1
    print_list(ele_list)
    print(num_swap)

N = int(input())
ele_list = list(map(int, input().split()))

bubble_sort(ele_list)
