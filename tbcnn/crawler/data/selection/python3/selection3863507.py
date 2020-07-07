#coding: utf-8

swap = 0
n = int(input())
a = list(map(int, input().split()))
for i in range(n):
    minj = i
    for j in range(i, n):
        if a[j] < a[minj]:
            minj = j
    if minj > i:
	    temp = a[i]
	    a[i] = a[minj]
	    a[minj] = temp
	    swap += 1
print(' '.join([str(i) for i in a]))
print(swap)
