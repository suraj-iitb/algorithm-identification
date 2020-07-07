import math
def merge(x, left, mid, right):
    global m
    n1 = mid - left
    n2 = right - mid
    l = x[left:left + n1]
    r = x[mid:mid + n2]
    l.append(10e10)
    r.append(10e10)
    i = 0
    j = 0
    for k in range(left, right):
        m += 1
        if l[i] < r[j]:
            x[k] = l[i]
            i += 1
        else:
            x[k] = r[j]
            j += 1
 
def mergeSort(x, left, right):
    if left + 1 < right:
        mid = math.ceil((left + right) / 2)
        mergeSort(x, left, mid)
        mergeSort(x, mid, right)
        merge(x, left, mid, right)
 
n = int(input())
x = list(map(int,input().split()))
m = 0
mergeSort(x, 0, n)
print(" ".join(map(str, x)))
print(m)
