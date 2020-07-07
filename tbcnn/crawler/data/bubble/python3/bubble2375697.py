# -*- coding: utf-8 -*-
"""
Created on Sat Jun 17 09:42:24 2017

@author: syaga
"""

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    flag = 1
    num = 0
    while flag:
        flag = 0
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                temp = A[j]
                A[j] = A[j-1]
                A[j-1] = temp
                flag = 1
                num += 1
    print(" ".join(map(str, A)))
    print(num)
