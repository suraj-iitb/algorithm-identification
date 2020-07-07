from typing import MutableSequence


def insertion_sort(A_list: MutableSequence, num: int) -> None:
    """挿入ソート"""
    for i in range(num):

        j = i
        tmp = A_list[i]

        while j > 0 and A_list[j - 1] > tmp:
            A_list[j] = A_list[j - 1]
            j -= 1

        A_list[j] = tmp
        print_list = [str(i) for i in A_list]
        print(' '.join(print_list))


if __name__ == '__main__':
    n = int(input())
    input_list = [int(x) for x in input().split()]

    insertion_sort(input_list, n)
