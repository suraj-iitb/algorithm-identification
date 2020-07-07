# -*- coding: utf-8 -*-

infinity = pow(10, 9) + 1


def merge(ns, left, mid, right):
    global count
    left_ns = ns[left:mid] + [infinity]
    right_ns = ns[mid:right] + [infinity]
    i = j = 0
    for k in range(left, right):
        count += 1
        if left_ns[i] <= right_ns[j]:
            ns[k] = left_ns[i]
            i += 1
        else:
            ns[k] = right_ns[j]
            j += 1


def merge_sort(ns, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(ns, left, mid)
        merge_sort(ns, mid, right)
        merge(ns, left, mid, right)


n = int(input())
ns = [int(e) for e in input().split()]
# n = 10
# ns = [8, 5, 9, 2, 6, 3, 7, 1, 10, 4]
left = 0
right = len(ns)
count = 0
merge_sort(ns, left, right)

print(*ns)
print(count)
