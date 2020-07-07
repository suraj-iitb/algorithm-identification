# -*- coding: utf-8 -*-
"""
Created on Thu May  3 19:22:34 2018
ALDS-1-5-C
@author: maezawa
"""
cnt = 0
n = int(input())
a = list(map(int, input().split()))

def merge_sort(a, left, right):
    #global cnt
    #cnt += 1
    if left+1 < right:
        mid = (left+right)//2
        merge_sort(a, left, mid)
        merge_sort(a, mid, right)
        merge(a, left, mid, right)

def merge(a, left, mid, right):
    global cnt
    n1 = mid - left
    n2 = right - mid
    
    l = a[left:mid].copy()
    r = a[mid:right].copy()
    
    l.append(10**10)
    r.append(10**10)
    i = 0
    j = 0
    
    for k in range(left, right):
        cnt += 1
        if l[i] <= r[j]:
            a[k] = l[i]
            i += 1
        else:
            a[k] = r[j]
            j += 1
            
merge_sort(a, 0, len(a))
print(a[0], end='')
for i in range(1,len(a)):
    print(' {}'.format(a[i]), end='')
print()
print(cnt)
    
