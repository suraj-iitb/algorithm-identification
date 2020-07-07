import copy


def partition(a, p, r):
    x = int(a[r][1])
    i = p - 1
    for j in range(p, r):
        if int(a[j][1]) <= x:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[r] = a[r], a[i + 1]
    return i + 1


def quickSort(a, p, r):
    if p < r:
        q = partition(a, p, r)
        quickSort(a, p, q - 1)
        quickSort(a, q + 1, r)


n = int(input())
s = []
for i in range(n):
    s.append(input().split())

l = copy.deepcopy(s)
l.sort(key=lambda x: x[1])

quickSort(s, 0, n - 1)

print("Stable" if s == l else "Not stable")
for v in s:
    print(" ".join(v))
