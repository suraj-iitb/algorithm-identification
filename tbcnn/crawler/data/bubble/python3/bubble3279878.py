import sys


def bubble_sort(a):
    count = 0
    flag = True
    while flag:
        flag = False
        for j in range(len(a) - 1, 0, -1):
            if a[j] < a[j - 1]:
                count += 1
                a[j], a[j - 1] = a[j - 1], a[j]
                flag = True
    return count


n = int(sys.stdin.readline())
a = [int(v) for v in sys.stdin.readline().strip().split()]
count = bubble_sort(a)
print(' '.join(map(str, a)))
print(count)

