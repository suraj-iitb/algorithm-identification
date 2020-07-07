# coding:utf-8

def printline(data):
    l=""
    for i,s in enumerate(data):
        l = l + str(s)
        if i+1 != len(data):
            l = l+" "
    print(l)


length = int(input())
data = list(map(int,input().split()))
printline(data)
for i in range(1,len(data)):
    tmp = data[i]
    i2 = i - 1
    while i2 >=0 and data[i2] > tmp:
        data[i2+1] = data[i2]
        i2 -= 1

    data[i2+1] = tmp
    printline(data)
