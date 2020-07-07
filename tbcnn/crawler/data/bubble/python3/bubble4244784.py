from typing import MutableSequence


def bubble_sort(a_list: MutableSequence, n:int) -> int:
    """バブルソート"""
    sw_cnt = 0
    for i in range(n - 1):
        for j in range(n -1, i, -1):
            if a_list[j - 1] > a_list[j]:
                a_list[j - 1], a_list[j] = a_list[j], a_list[j - 1]
                sw_cnt += 1

    print_list = [str(i) for i in a_list]
    print(' '.join(print_list))
    print(sw_cnt)

    
if __name__ == "__main__":
    n = int(input())
    input_list = [int(x) for x in input().split()]

    bubble_sort(input_list, n)
