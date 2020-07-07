def partition(a, p, r):
    x = a[r][1]
    i = p - 1
    for j in range(p, r):
        if a[j][1] <= x:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[r], a[i + 1] = a[i + 1], a[r]
    return i + 1


def quick_sort(a, p, r):
    if p < r:
        q = partition(a, p, r)
        quick_sort(a, p, q - 1)
        quick_sort(a, q + 1, r)


#
# l = [int(i) for i in input().split()]
# quick_sort(l, 0, len(l) - 1)
# print(l)

n = int(input())
l = []

for i in range(n):
    a, b = input().split()
    l.append((a, int(b)))

l1 = l.copy()
quick_sort(l1, 0, len(l) - 1)
# print(l1)

l2 = l.copy()
l2_sorted = sorted(l2, key=lambda x: x[1])
# print(l2_sorted)

if l1 == l2_sorted:
    print("Stable")
else:
    print("Not stable")

for x, y in l1:
    print(x, y)

