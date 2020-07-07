def merge(a, left, mid, right):
    L = a[left:mid] + [INF]
    R = a[mid:right] + [INF]
    
    i = 0
    j = 0
    for k in range(left, right):
     
        global idx
        idx += 1
        if( L[i] <= R[j] ):
            a[k] = L[i]
            i += 1
        else:
            a[k] = R[j]
            j += 1

def merge_sort(a, left, right):
    if( left + 1 < right ):
        mid = (left + right) // 2 
        merge_sort(a, left, mid)
        merge_sort(a, mid, right)
        merge(a, left, mid, right)


INF = 1000000000
idx = 0
n = int(input())
a = [int(i) for i in input().split()]
merge_sort(a,0,len(a))
print(*a)
print(idx)
