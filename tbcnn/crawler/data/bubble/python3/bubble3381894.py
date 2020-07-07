# coding: utf-8

def printA(a, n):
    for i in range(n):
        print(a[i],end="")
        if i < n - 1:
            print(" ", end="")
        else:
            print()

def bubbleSort(a, n):
    count = 0
    flag = True
    while flag:
        flag = False
        for j in range(n-1,0,-1):
            if a[j] < a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]
                count += 1
                flag = True
    return count

n = int(input().rstrip())
a = list(map(int,input().rstrip().split()))
c = bubbleSort(a, n)
printA(a,n)
print(c)
