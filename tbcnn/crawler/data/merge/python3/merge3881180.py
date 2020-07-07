cnt = 0
def merge(a, left, mid, right):
    global cnt
    l = 0
    l_e = mid - left
    r = 0
    r_e = right - mid - 1

    L = a[left:mid + 1]
    R = a[mid + 1:right + 1]
    csr = left
    while l <= l_e and r <= r_e:
        cnt += 1
        if L[l] < R[r]:
            a[csr] = L[l]
            l += 1
        else:
            a[csr] = R[r]
            r += 1
        csr += 1
    if l == l_e + 1:
        while r <= r_e:
            a[csr] = R[r]
            r += 1
            csr += 1
            cnt += 1
    else:
        while l <= l_e:
            a[csr] = L[l]
            l += 1
            csr += 1
            cnt += 1

def merge_sort(a, l, r):
    mid = (l + r) // 2
    if l < r:
        merge_sort(a, l, mid)
    if l + 1 < r:
        merge_sort(a, mid + 1, r)
    if l < r:
        merge(a, l, mid, r)


n = int(input())
a = [int(i) for i in input().split()]
merge_sort(a, 0, n - 1)
print(' '.join(map(str, a)))
print(cnt)

