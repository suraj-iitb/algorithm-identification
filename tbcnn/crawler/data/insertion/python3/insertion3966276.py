# -*- coding: utf-8 -*-
# ALDS1_1_A:   Insertion Sort

def insertion_sort(a, n):
    for i in range(1, n):
        print(*a)
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]
            j -= 1
            a[j+1] = v
    print(*a)

n = int(input())
a = list(map(int, input().split()))

insertion_sort(a, n)
