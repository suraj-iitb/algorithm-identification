
def merge(a, left, mid, right):
    x = 0
    l = a[left:mid] + [float("inf")]
    r = a[mid:right] + [float("inf")]
    i = 0
    j = 0
    for k in range(left,right):
        if l[i] <= r[j]:
            a[k] = l[i]
            i += 1
        else :
            a[k] = r[j]
            j += 1
        x += 1
    return x

def mergeSort(a, left, right,x):
    if left+1 < right:
        mid = int((left + right)/2)
        mergeSort(a, left, mid,x)
        mergeSort(a, mid, right,x)
        x[0] += merge(a, left, mid, right)

n = int(input())
s = list(map(int,input().split()))
x = [0]
mergeSort(s,0,n,x)
print(*s)
print(x[0])


