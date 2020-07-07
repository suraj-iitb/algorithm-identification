from typing import MutableSequence


def selection_sort(a_list: MutableSequence, n: int) -> int:
    """単純選択ソート"""
    sw_cnt = 0
    for i in range(n - 1):
        min = i
        for j in range(i + 1, n):
            if a_list[j] < a_list[min]:
                min = j

        if i != min:
            sw_cnt += 1

        a_list[i], a_list[min] = a_list[min], a_list[i]

    print_list = [str(i) for i in a_list]
    print(' '.join(print_list))
    print(sw_cnt)


if __name__ == '__main__':
    n = int(input())
    input_list = [int(x) for x in input().split()]

    selection_sort(input_list, n)


