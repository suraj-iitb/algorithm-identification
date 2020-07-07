# -*- coding: utf-8 -*-
"""
Created on Sun Jun 18 10:42:00 2017

@author: syaga
"""

import math

def insertionSort(A, n, g, cnt):
    for i in range(g, n):
        v = A[i]
        j = i-g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
    return cnt
         
def shellSort(A, n):
    cnt = 0
    G = [1]
    if n != 1:
        for i in range(99):
            G.append(G[i]*3+1)
        G = [x for x in G if x < n]
        G.reverse()
    m = len(G)
    print(m)
    print(" ".join(map(str, G)))
    for i in range(0, m):
        cnt = insertionSort(A, n, G[i], cnt)
    print(cnt)

if __name__ == "__main__":
    n = int(input())
    A = []
    for i in range(n):
        A.append(int(input()))
    shellSort(A, n)
    for i in A:
        print(i)
