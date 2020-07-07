#coding: utf-8

swap = 0
n = int(input())
a = list(map(int, input().split()))
for i in range(n - 1):
    for j in range(n - 1 - i):
        if a[j] > a[j + 1]:
            temp = a[j]
            a[j] = a[j + 1]
            a[j + 1] = temp
            swap += 1
print(' '.join([str(i) for i in a]))
print(swap)
