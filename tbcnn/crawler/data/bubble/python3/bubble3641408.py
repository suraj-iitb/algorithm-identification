#!/usr/bin/env python3 
# coding=utf_8

n = int(input())
adata = input().split()
data = list(map(int, adata))
count = 0

flag = True
while flag:
    flag = False
    for i in range(len(data)-1,0,-1):
        if data[i] < data[i-1]:
            tmp = data[i]
            data[i] = data[i-1]
            data[i-1] = tmp
            count +=1
            flag = True
ans = ""
for s in data:
    if ans != "":
        ans = ans+ " "
    ans = ans + str(s)



print(ans)
print(count)


