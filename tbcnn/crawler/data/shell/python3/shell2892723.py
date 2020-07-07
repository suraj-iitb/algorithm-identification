N = int(input())
ary = [int(input()) for _ in range(N)]


def insertion_sort(ary, g):
    cnt = 0

    for i in range(g, N):
        v = ary[i]
        j = i - g

        while j >= 0 and ary[j] > v:
            ary[j + g] = ary[j]
            j -= g
            cnt += 1

        ary[j + g] = v

    return cnt


def shell_sort(ary):

    g = [1]
    while True:
        if 3 * g[-1] + 1 < N:
            g.append(3 * g[-1] + 1)
        else:
            break

    m = len(g)
    g = g[::-1]
    cnt = 0
    for i in range(0, m):
        cnt += insertion_sort(ary, g[i])

    print(m)
    print(' '.join([str(_) for _ in g]))
    print(cnt)
    [print(_) for _ in ary]


shell_sort(ary)

