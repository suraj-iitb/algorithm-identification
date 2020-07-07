# -*- coding: utf-8 -*-


def insertion_sort(seq, l):
    print(' '.join([str(n) for n in seq]))
    for i, v in enumerate(seq[1:], start=1):
        left = i - 1
        while left >= 0 and seq[left] > v:
            seq[left], seq[left+1] = seq[left+1], seq[left]
            left -= 1
        print(' '.join([str(n) for n in seq]))


def to_int(v):
    return int(v)


def to_seq(v):
    return [int(c) for c in v.split()]


if __name__ == '__main__':
    l = to_int(input())
    seq = to_seq(input())

    insertion_sort(seq, l)
