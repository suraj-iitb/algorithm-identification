n = int(input())
l = list(map(int, input().split()))

print(*l)


def insertionsort(a, n):
    for i in range(1, n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = v
        print(*a)


insertionsort(l, n)

