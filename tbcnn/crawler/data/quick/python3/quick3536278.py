a = []
b = {}
n = int(input())
for _ in range(n):
    s, i = input().split()
    a += [(s, int(i))]
    b.setdefault(int(i), []).append(s)
b = {val: iter(s).__next__ for val, s in b.items()}

def partition(a, left, right):
    standard = a[right][1]
    cnt = left
    for i in range(left, right):
        if a[i][1] <= standard:
            a[cnt],a[i] = a[i], a[cnt]
            cnt += 1
    a[cnt],a[right] = a[right], a[cnt]
    return cnt

def quickSort(a, left = 0, right = len(a) - 1):
    if 1 <= right - left:
        cnt_ = partition(a, left, right)
        quickSort(a,left, cnt_ - 1)
        quickSort(a,cnt_ + 1, right)

quickSort(a, 0 , len(a)-1)

ok = 1
for s, i in a:
    if b[i]() != s:
        ok = 0
print(['Not stable','Stable'][ok])


for i in range(n):
    print(*a[i])
