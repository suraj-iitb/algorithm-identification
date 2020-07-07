#! /usr/bin/python
# -*- coding: utf-8 -*-
# ALDS1_2_D: Shell Sort

import copy
import math

def insertionSort(A, N, g):
    global cnt
    for i in range(g, N):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
    return A

def shellSort(A, N):
    # print("ShellSort")
    global cnt
    i = 0
    # m = int(math.ceil(N**1.5))
    # print("m is {}".format(m))
    G = [1]
    # for i in range(0, m):
    #     G.append(3*G[i] + 1)
    while 3*G[i] + 1 < len(A):
        G.append(3*G[i] + 1)
        i += 1
    m = len(G)
    print(m)
    G_AFTER = list(reversed(G))
    print(*G_AFTER)
    for i in range(0, m):
        # print("G[i] = {}".format(G_AFTER[i]))
        insertionSort(A, N, G_AFTER[i])
    return A

if __name__ == "__main__":
    # 数字入力　行数＋数字
    cnt = 0
    N=int(input()) #行数
    A=[int(input()) for i in range(N)]
    ANS = shellSort(A, N)
    print(cnt)
    for i in range(len(ANS)):
        print(ANS[i])
