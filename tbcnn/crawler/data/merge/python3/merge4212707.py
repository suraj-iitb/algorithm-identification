def merge(a, left, mid, right):
    """ merge list a[left:mid] and a[mid:right], assuming the lists is sorted
    """
    global cnt
    inf = 10 ** 9
    left_a = a[left:mid] + [inf]
    right_a = a[mid:right] + [inf]
    
    i, j = 0, 0

    for k in range(left, right):
        if left_a[i] <= right_a[j]:
            a[k] = left_a[i]
            i += 1
        else:
            a[k] = right_a[j]
            j += 1

        cnt += 1


def merge_sort(a, left, right):
    """ split list a[left:right-1] into two lists and merge
    """
    if left + 1 < right:
        mid = (left + right)//2
        merge_sort(a, left, mid)
        merge_sort(a, mid, right)
        merge(a, left, mid, right)

n = int(input())
a = list(map(int, input().split()))
cnt = 0
merge_sort(a, 0, n)

print(' '.join(str(n) for n in a))
print(cnt)
