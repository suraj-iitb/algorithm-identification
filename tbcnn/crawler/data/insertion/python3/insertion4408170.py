n = int(input())
num_list = list(map(int, input().split()))
def insertion_sort(lst):
    n = len(lst)
    for i in range(n):
        current = lst[i]
        j = i - 1
        while j >= 0 and lst[j] > current:
            lst[j + 1] = lst[j]
            j -= 1
        lst[j + 1] = current
        map_lst = map(str, lst)
        print(" ".join(map_lst))
insertion_sort(num_list)
