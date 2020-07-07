# coding: utf-8

def printA(a, n):
    for i in range(n):
        print(a[i],end="")
        if i < n - 1:
            print(" ", end="")
        else:
            print()

def insertionSort(a, n):
    printA(ai, n)
    for i in range(1,n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v
        printA(ai, n)

num = int(input().rstrip())
ai = list(map(int,input().rstrip().split()))
insertionSort(ai, num)
