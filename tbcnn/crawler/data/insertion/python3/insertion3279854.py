import sys


def insertion_sort(a):
    print(' '.join(map(str, a)))
    for i in range(1, len(a)):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = v
        print(' '.join(map(str, a)))


n = int(sys.stdin.readline())
a = [int(v) for v in sys.stdin.readline().strip().split()]
insertion_sort(a)

