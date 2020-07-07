n = int(input())
s = list(map(int,input().split()))
count = 0
 
def merge(a, left, mid, right):
    global count
    l = a[left:mid] + [float("inf")]
    r = a[mid:right] + [float("inf")]
    i = j = 0
    for k in range(left, right):
        if l[i] <= r[j]:
            a[k] = l[i]
            i += 1
        else:
            a[k] = r[j]
            j += 1
    count += right - left
 
def mergeSort(a, left, right):
    if left + 1 < right:
        mid = right + (left - right)//2
        mergeSort(a, left, mid)
        mergeSort(a, mid, right)
        merge(a, left, mid, right)
 
mergeSort(s, 0, n)
 
print(*s)
print(count)

