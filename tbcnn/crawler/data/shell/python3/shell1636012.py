def insertion_sort(a, n, g, cnt):
    for i in range(g, n):
        v, j = a[i], i - g
        while j >= 0 and a[j] > v:
            a[j + g] = a[j]
            j = j - g
            cnt += 1
        a[j + g] = v
    return cnt


n = int(input())
a = list(int(input()) for _ in range(n))

m, g, glist, cnt = 0, 1, [], 0
while g <= n:
    m += 1
    glist.append(g)
    g = 4 ** m + 3 * 2 ** (m - 1) + 1

glist.reverse()

for g in glist:
    cnt = insertion_sort(a, n, g, cnt)

print(m)
print(*glist)
print(cnt)
print('\n'.join(map(str, a)))
