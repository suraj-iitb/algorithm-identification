def insertion_sort(n, l, g=1):
    count = 0
    for i in range(1, n):
        v = l[i]
        j = i-g
        while j >= 0 and l[j] > v:
            l[j+g] = l[j]
            j -= g
            count += 1
        l[j+g] = v
    return l, count

def shell_sort(n, l):
    h = 1
    G = []
    while h <= n:
        G.insert(0, h)
        h = 3*h + 1
    print(len(G))
    print(' '.join(map(str, G)))
    cnt = 0
    for i in range(len(G)):
        l, count = insertion_sort(n, l, g=G[i])
        cnt += count
    print(cnt)
    for i in range(len(l)):
        print(l[i])

if __name__=='__main__':
    n = int(input())
    l = []
    for _ in range(n):
        l.append(int(input()))
    shell_sort(n, l)

