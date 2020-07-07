#!/usr/bin/python
# coding=utf-8


MAX = 10000

def getdata():
    data = map(int, input().split())
    return (list(data))

def countsort(data, max):
    C =[0*x for x in range(0,max)]

    for i in data:
        C[i] += 1

    for i in range(1,max):
        C[i] = C[i] + C[i-1]
    
    B = [i*0 for i in data]
    for i in range(len(data)-1, -1,-1):
        B[C[data[i]]-1] = data[i]   
        C[data[i]] -= 1

    return B

getdata()
ans = countsort(getdata(),MAX)
print(" ".join(map(str,ans)))



