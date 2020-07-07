def insertion_sort(a, n, g):
    cnt = 0
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j -= g
            cnt += 1
        a[j+g] = v

    return cnt


def shell_sort(a, n):
    cnt = 0
    g = []
    h = 1
    while h <= n:
        g.append(h)
        h = 3 * h + 1
    g = g[::-1]

    for gi in g:
        cnt += insertion_sort(a, n, gi)

    return cnt, g


n = int(input())
a = []
for i in range(n):
    a.append(int(input()))

cnt, g = shell_sort(a, n)

print(len(g))
print(' '.join([str(i) for i in g]))
print(cnt)
for i in a:
    print(i)
