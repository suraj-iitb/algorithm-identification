# -*- coding: utf-8 -*-


def insertion_sort(a, n):
    for i in range(n):
        tmp = a[i]
        j = i - 1
        while j >= 0 and a[j] > tmp:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = tmp
        print(' '.join(map(str, a)))

if __name__ == '__main__':
    n = int(input())
    a = [int(n) for n in input().split()]
    insertion_sort(a, n)
