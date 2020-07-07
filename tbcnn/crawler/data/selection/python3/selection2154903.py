# -*- coding:utf-8 -*-

n = int(input())
str = input()
str = str.split()
a = []
for i in range(n):
    a.append(int(str[i]))

count = 0
for i in range(n):
    min = i
    for j in range(i,n):
        if a[j] < a[min]:
            min = j

    tmp = a[min]
    a[min] = a[i]
    a[i] = tmp
    if a[min] != a[i]:
        count += 1
for i in range(n-1):
    print(a[i],end = ' ')
print(a[n-1])
print(count)
