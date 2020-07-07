cnt = 0


def merge(a, left, mid, right):
    global cnt
    i = left
    j = mid+1
    b = []
    while i <= mid and j <= right:
        if a[i] <= a[j]:
            cnt+=1
            b.append(a[i])
            i += 1
        else:
            cnt+=1
            b.append(a[j])
            j += 1
    if i == mid+1:
        while j <= right:
            cnt+=1
            b.append(a[j])
            j += 1
    else:
        while i <= mid:
            cnt+=1
            b.append(a[i])
            i += 1
    a[left:right+1] = b


def merge_sort(a, left, right):
    if left == right:
        return

    mid = (left+right)//2
    merge_sort(a, left, mid)
    merge_sort(a, mid+1, right)
    merge(a, left, mid, right)

n = int(input())
l = list(map(int,input().split()))
merge_sort(l,0,n-1)
for i in range(n-1):
    print(l[i],end = ' ')
print(l[-1])
print(cnt)
