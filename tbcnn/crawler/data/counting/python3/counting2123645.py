# -*- coding: utf-8 -*-
def CountingSort(array,maxval):
    m=maxval+1
    count=[0]*m
    for a in array:
        count[a]+=1
    i=0
    for a in range(m):
        for c in range(count[a]):
            array[i]=a
            i+=1
    return array

if __name__ == '__main__':
    maxval = 2000000
    n = int(input())
    a = [int(i) for i in input().split()]
    print(" ".join([str(s) for s in CountingSort(a,max(a))]))
