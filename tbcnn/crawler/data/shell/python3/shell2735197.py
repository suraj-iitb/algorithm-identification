cnt = 0
m = 0
g = []

def insertion_sort(a, n, g):
# cnt+=1 のときにローカルスコープの外を見にいくようにするため
    global cnt
    for i in range(g, n):
        v = a[i]
        k = i - g
        while k >= 0 and a[k] > v:
            a[k+g] = a[k]
            k -= g
            cnt += 1
        a[k+g] = v

def shell_sort(a, n):
    global m, g
    h = 1
    while h <= n:
        g.append(h)
        h = h * 3 + 1
    g.reverse()
    m = len(g)
    for i in range(m):
        insertion_sort(a, n, g[i])

n = int(input())
a = [int(input()) for i in range(n)]
shell_sort(a, n)
print(m)
print(*g)
print(cnt)
for i in a:
    print(i)
