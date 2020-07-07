def insertionSort(a, n):
    trace(a, n)
    for i in range(1, n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v
        trace(a, n)


def trace(a, n):
    output = ''
    for i in a:
        if i == a[n-1]:
            output += str(i)
        else:
            output += str(i) + ' '
    print(output)

n = int(input())
a = list(map(int, input().split()))
insertionSort(a, n)
