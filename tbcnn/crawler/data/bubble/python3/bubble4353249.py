# -*- coding:utf8 -*-

n = int(input())
l = list(map(int, input().split()))
c = 0
flag = 1
while flag:
    flag = 0
    for i in reversed(range(1, n)):
        if l[i] < l[i - 1]:
            l[i], l[i - 1] = l[i - 1], l[i]
            flag = 1
            c += 1
print(' '.join(map(str, l)))
print(c)
