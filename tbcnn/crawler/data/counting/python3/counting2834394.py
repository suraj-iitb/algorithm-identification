# -*- coding: utf-8 -*-
"""
Created on Thu May  3 22:47:34 2018
ALDS1_6_A
@author: maezawa
"""

n = int(input())
a = list(map(int, input().split()))
b = [0 for _ in range(n+1)]

def counting_sort(a, b, k):
    c = [0 for _ in range(k+1)]
    
    for aj in a:
        c[aj] += 1
    
    for i in range(1, k+1):
        c[i] += c[i-1]
        
    for j in reversed(range(n)):
        #print(j, a[j], c[a[j]])
        b[c[a[j]]] = a[j]
        c[a[j]] -= 1
    
k = max(a)    
counting_sort(a, b, k)
print(b[1],end='')
for i in range(2,n+1):
    print(' {}'.format(b[i]), end='')
print()
