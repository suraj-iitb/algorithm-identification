#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def print_array(a):
    print(" ".join(map(str, a)))


def insertion_sort(a, n):
    print_array(a)
    for i in range(1, n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = v
        print_array(a)
    return a


def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = insertion_sort(a, n)

if __name__ == "__main__":
    main()
