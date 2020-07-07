# coding: utf-8

def printA(a, n):
    for i in range(n):
        print(a[i],end="")
        if i < n - 1:
            print(" ", end="")
        else:
            print()

def selectionSort(a, n):
    count = 0
    for i in range(n):
        minj = i
        for j in range(i,n):
            if a[j] < a[minj]:
                minj = j
        a[i],a[minj] = a[minj], a[i]
        if i != minj:
            count += 1
    return count

n = int(input().rstrip())
a = list(map(int,input().rstrip().split()))
c = selectionSort(a, n)
printA(a, n)
print(c)
