n = int(input())
a = [int(x) for x in input().split()]

def printlist(l):
    print(' '.join(map(str, l)))

def insertion_sort(a, n):
    for i in range(1, n):
        printlist(a)
        v = a[i]
        j = i-1
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v

insertion_sort(a,n)
printlist(a)
