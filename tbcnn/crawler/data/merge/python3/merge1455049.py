def merge(a, left, mid, right):
    global count
    l = a[left:mid] + [sentinel]
    r = a[mid:right] + [sentinel]
    i = j = 0
    for k in range(left, right):
        if l[i] <= r[j]:
            a[k] = l[i]
            i += 1
        else:
            a[k] = r[j]
            j += 1
    count += right - left


def merge_sort(a, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(a, left, mid)
        merge_sort(a, mid, right)
        merge(a, left, mid, right)

sentinel = 1000000001

n = int(input())
a = list(map(int, input().split()))
count = 0
merge_sort(a, 0, len(a))
print(*a)
print(count)
