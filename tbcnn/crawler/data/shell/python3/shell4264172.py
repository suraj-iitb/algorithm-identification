def insertion_sort(a, g, n):
    cnt = 0
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j + g] = a[j]
            j = j - g
            cnt += 1
        a[j + g] = v
    return cnt

def shell_sort(a, n):
    cnt = 0
    g = []
    h = 1
    while h <= n:
        g.append(h)
        h = 3 * h + 1
    g.reverse()
    m = len(g)
    print(m)
    print(*g)
    for i in range(m):
        cnt += insertion_sort(a, g[i], n)
    print(cnt)

n = int(input())
a = [int(input()) for _ in range(n)]

shell_sort(a, n)
print('\n'.join(map(str, a)))

