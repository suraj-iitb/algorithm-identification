# -*- coding:utf-8 -*-
import sys


def merge(lst, left, mid, right):
    L = lst[left: mid]
    R = lst[mid: right]
    l_len = len(L)
    r_len = len(R)
    cnt = 0
    i = 0
    j = 0
    for k in range(left, right):
        cnt += 1
        if l_len <= i:
            lst[k] = R[j]
            j += 1
        elif r_len <= j:
            lst[k] = L[i]
            i += 1
        elif L[i] <= R[j]:
            lst[k] = L[i]
            i += 1
        else:
            lst[k] = R[j]
            j += 1
    return cnt


def mergeSort(lst, left, right):
    if left + 1 < right:
        mid = (left + right) >> 1
        cnt = mergeSort(lst, left, mid)
        cnt += mergeSort(lst, mid, right)
        return merge(lst, left, mid, right) + cnt
    else:
        return 0


if __name__ == "__main__":
    lst = [val.split() for val in sys.stdin.read().splitlines()]
    data = [int(n) for n in lst[1]]
    cnt = mergeSort(data, 0, int(lst[0][0]))
    print(" ".join([str(n) for n in data]))
    print(cnt)
