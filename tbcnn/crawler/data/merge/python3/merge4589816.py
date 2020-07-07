# -*- coding: utf-8 -*-
from sys import stdin

n = int(stdin.readline().rstrip())
*A, = map(int, stdin.readline().split())
cnt = 0

def merge(A, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    L = [A[left + i] for i in range(n1)]
    R = [A[mid + i] for i in range(n2)]
    L.append(10 ** 9)
    R.append(10 ** 9)
    i = 0
    j = 0
    for k in range(left, right):
        # print(" ".join(map(str,A)))#TODO
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    global cnt
    cnt += right - left  # !

def merge_sort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)

merge_sort(A, 0,n)
print(" ".join(map(str, A)))
print(cnt)
