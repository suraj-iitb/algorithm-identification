#!/usr/local/bin python
# -*- coding: utf-8 -*-
#
# ~/aizu/alds11a_insertionSort.py
#


def insertionSort(a: list, n: int):
    a_string_list = map(str, a)
    output = ' '.join(a_string_list)
    print(output)
    for i in range(1, n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = v
        a_string_list = map(str, a)
        output = ' '.join(a_string_list)
        print(output)


n = int(input())
a = list(map(int, input().split()))
# print(a)
insertionSort(a, n)


