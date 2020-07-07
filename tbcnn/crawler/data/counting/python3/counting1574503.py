#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import array
import sys


def counting_sort(a, n, k=10000):
    b = array.array("I", (0 for x in range(n)))
    c = array.array("I", (0 for x in range(k + 1)))
    for j in range(0, n):
        c[a[j]] += 1
    for i in range(0, k + 1):
        c[i] += c[i - 1]
    for j in range(n - 1, -1, -1):
        b[c[a[j]] - 1] = a[j]
        c[a[j]] -= 1
    return b


def main():
    n = int(sys.stdin.readline())
    a = array.array("I", map(int, sys.stdin.readline().split()))
    print(" ".join(map(str, counting_sort(a, n))))


if __name__ == "__main__":
    main()
