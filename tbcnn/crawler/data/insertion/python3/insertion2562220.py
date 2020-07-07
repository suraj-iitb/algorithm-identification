#! /usr/bin/env python
# -*- coding : utf-8 -*-
input()
seq = [int(x) for x in input().split()]
for i in range(0, len(seq)):
    key = seq[i]
    j = i - 1
    assert isinstance(i, int)
    while j >= 0 and seq[j] > key:
        seq[j + 1] = seq[j]
        j -= 1
    seq[j + 1] = key
    print(' '.join(map(str,seq)))
