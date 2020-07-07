def insertion_sort(a, n, g, cnt):
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j = j -g
            cnt += 1
        a[j+g] = v
    return cnt

def shell_sort(a, n):
    cnt = 0
    h = 1
    g = []
    while h <= n:
        g.insert(0, h)
        h = 3 * h + 1

    for i in range(len(g)):
        if g[i] <= len(a):
            cnt = insertion_sort(a, n, g[i], cnt)

    print(len(g))
    print(' '.join(map(str, g)))
    print(cnt)


n = int(input())
a = [int(input()) for _ in range(n)]

shell_sort(a, n)
for num in a:
    print(num)

