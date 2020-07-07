N = int(input())
*A, = list(map(int, input().split()))
count = 0


def merge(a, left, mid, right):
    global count
    la = a[left:mid] + [float("inf")]
    ra = a[mid:right] + [float("inf")]

    i, j = 0, 0
    for k in range(left, right):
        count += 1
        if la[i] <= ra[j]:
            a[k] = la[i]
            i += 1
        else:
            a[k] = ra[j]
            j += 1


def merge_sort(a, left, right):
    if left + 1 < right:
        mid = int((left + right) / 2)
        merge_sort(a, left, mid)
        merge_sort(a, mid, right)
        merge(a, left, mid, right)

merge_sort(A, 0, N)
print(*A)
print(count)

