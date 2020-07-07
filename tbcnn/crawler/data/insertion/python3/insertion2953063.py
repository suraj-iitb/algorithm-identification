# Insertion Sort

n = int(input())
integers = [int(i) for i in input().rstrip().split()]

def show(a):
    for i in range(len(a)):
        if i < len(a) - 1:
            print(a[i], end = ' ')
    return a[len(a) - 1]

def insertionSort(a, n):
    for i in range(1, n):
        print(show(a))
        v = a[i]
        j = i - 1
        while j >= 0 and v < a[j]:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = v
    return show(a)

print(insertionSort(integers, n))

