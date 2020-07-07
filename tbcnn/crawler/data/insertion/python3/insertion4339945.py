# -*- coding:utf8 -*-

n = int(input())
l = list(map(int, input().split()))
for i in range(n):
    v = l[i]
    j = i - 1
    while j >= 0 and l[j] > v:
        l[j+1] = l[j]
        l[j] = v
        j -= 1
    print(' '.join(map(str, l)))

