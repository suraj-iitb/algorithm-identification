# -*- coding: utf-8 -*-
"""
Created on Sun Jun 18 09:48:56 2017

@author: syaga
"""

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    num = 0
    for i in range(0, N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        temp = A[i]
        A[i] = A[minj]
        A[minj] = temp
        if minj != i:
            num += 1
    print(" ".join(map(str, A)))
    print(num)
