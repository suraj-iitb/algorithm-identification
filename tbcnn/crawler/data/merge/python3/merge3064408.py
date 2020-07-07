count = 0

def merge(a, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    l = a[left:left+n1]
    r = a[mid:mid+n2]
    l.append(float('inf'))
    r.append(float('inf'))
    i = 0
    j = 0
    global count
    count += right - left
    for k in range(left, right):
        if l[i] <= r[j]:
            a[k] = l[i]
            i += 1
        else:
            a[k] = r[j]
            j += 1


def mergeSort(a, left, right):
    if left+1 < right:
        mid = (left+right) // 2
        mergeSort(a, left, mid)
        mergeSort(a, mid, right)
        merge(a, left, mid, right)


n = int(input())
a = [int(i) for i in input().split()]

mergeSort(a, 0, n)

print(' '.join([str(v) for v in a]))
print(count)
