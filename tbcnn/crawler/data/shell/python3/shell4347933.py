def insertion_sort(l, n, g):
    global count
    for i in range(g, n):
        v = l[i]
        j = i - g
        while j >= 0 and l[j] > v:
            l[j + g] = l[j]
            j -= g
            count += 1
        l[j + g] = v


def shell_sort(l, n):
    for i in range(m):
        insertion_sort(l, n, G[i])


def make_g(length):
    if length == 1:
        return [1]

    G = []
    while True:
        if length == 1:
            break
        G.append(length // 2)
        length //= 2
    return G


n = int(input())
l = []
for i in range(n):
    l.append(int(input()))

count = 0
G = make_g(len(l))
m = len(G)

shell_sort(l, n)

print(m)
print(' '.join(map(str, G)))
print(count)
for i in l:
    print(i)

