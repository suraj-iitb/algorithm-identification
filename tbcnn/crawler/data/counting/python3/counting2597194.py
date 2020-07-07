# -*- coding:utf-8 -*-


def countingSort(lst, n):
    cnt_lst = [0] * (max(lst)+1)

    for i in range(0, n):
        cnt_lst[lst[i]] += 1

    i = 0
    result = []
    for j, cnt in enumerate(cnt_lst):
        for _ in range(0, cnt):
            result.append(j)
    return result


if __name__ == "__main__":
    n = int(input())
    lst = [int(val) for val in input().split()]
    result = countingSort(lst, n)
    print(" ".join([str(val) for val in result]))
