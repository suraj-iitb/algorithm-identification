# -*- coding: utf-8 -*-
n = int(input())
a = list(map(int, input().split()))

count = 0
for i in range(n):
    for j in range(n - 1, i, -1):
        if a[j] < a[j - 1]:
            count += 1
            tmp = a[j - 1]
            a[j - 1] = a[j]
            a[j] = tmp

print(" ".join(map(str, a)))
print(count)

