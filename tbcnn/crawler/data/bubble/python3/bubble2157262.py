# -*- coding: utf-8 -*-


def bubble_sort(seq, l):
    cnt = 0

    for max_size in range(l, 0, -1):
        for left in range(1, max_size):
            if seq[left-1] > seq[left]:
                seq[left-1], seq[left] = seq[left], seq[left-1]
                cnt += 1

    print(' '.join([str(i) for i in seq]))
    print(cnt)


def to_int(v):
    return int(v)


def to_seq(v):
    return [int(c) for c in v.split()]


if __name__ == '__main__':
    l = to_int(input())
    seq = to_seq(input())

    bubble_sort(seq, l)
