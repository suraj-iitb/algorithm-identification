# coding: utf-8
def merge_sort(a, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(a, left, mid)
        merge_sort(a, mid, right)
        merge(a, left, mid, right)

def merge(a, left, mid, right):
    global cnt
    global inf

    l = a[left:mid]
    r = a[mid:right]

    l.append(inf)
    r.append(inf)

    i, j = 0, 0

    for k in range(left, right, 1):
        cnt += 1
        if l[i] <= r[j]:
            a[k] = l[i]
            i += 1
        else:
            a[k] = r[j]
            j += 1


cnt = 0
inf = 1 << 32

n = int(input())
a = [int(x) for x in input().split(" ")]

merge_sort(a, 0, len(a))
print(" ".join(map(str, a)))
print(cnt)
