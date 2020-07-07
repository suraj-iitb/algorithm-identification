# coding: utf-8
n = int(input())
num = list(map(int, input().split()))
for i in range(n):
    tmp = num[i]
    j = i 
    while j>0 and num[j-1] > tmp:
        num[j] = num[j-1]
        j -= 1
    num[j] = tmp
    for i in range(n):
        if i==n-1:
            print(num[i], end='')
            break
        print(num[i], end=' ')
    print()
