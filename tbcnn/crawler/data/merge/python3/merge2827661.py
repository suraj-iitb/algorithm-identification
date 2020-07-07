import math
def merge(a, left, mid, right):
    global c
    n1 = mid - left
    n2 = right - mid
    l = a[left:left + n1]
    r = a[mid:mid + n2]
    l.append(10e10)
    r.append(10e10)
    i = 0
    j = 0
    for k in range(left, right):
        c += 1
        if l[i] < r[j]:
            a[k] = l[i]
            i += 1
        else:
            a[k] = r[j]
            j += 1

def mergeSort(a, left, right):
    if left + 1 < right:
        mid = math.ceil((left + right) / 2)
        mergeSort(a, left, mid)
        mergeSort(a, mid, right)
        merge(a, left, mid, right)

n = int(input())
a = list(map(int,input().split()))
c = 0
mergeSort(a, 0, n)
print(" ".join(map(str, a)))
print(c)
