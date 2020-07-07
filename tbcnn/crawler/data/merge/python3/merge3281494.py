import math
import sys


def merge(a, left, mid, right):
    count = 0

    a1 = a[left:mid] + [math.inf]
    a2 = a[mid:right] + [math.inf]

    i = j = 0
    for k in range(left, right):
        if a1[i] <= a2[j]:
            a[k] = a1[i]
            i += 1
        else:
            a[k] = a2[j]
            j += 1
        count += 1

    return count


def merge_sort(a, left, right):
    if left + 1 >= right:
        return 0

    count = 0
    mid = (left + right) // 2
    count += merge_sort(a, left, mid)
    count += merge_sort(a, mid, right)
    count += merge(a, left, mid, right)
    return count


n = int(sys.stdin.readline())
a = [int(v) for v in sys.stdin.readline().split()]
count = merge_sort(a, 0, len(a))

print(' '.join(map(str, a)))
print(count)

