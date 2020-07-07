import sys

def insertion_sort(a, n, g):
    count = 0
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j = j - g
            count += 1
        a[j+g] = v
    return count

def shell_sort(a, n):
    count = 0
    G = list([int((2.25**i-1)/1.25) for i in range(17, 0, -1)])
    G = [x for x in G if x <= n]
    m = len(G)
    for g in G:
        count += insertion_sort(a, n, g)
    return m, G, count, a

n = int(input())
a = list(map(int, sys.stdin))

m, G, count, a = shell_sort(a, n)
print(len(G))
print(*G)
print(count)
print("\n".join(map(str, a)))

