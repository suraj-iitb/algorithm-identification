def insertion_sort(l, g):
    cnt = 0
    for i in range(g, len(l)):
        tmp = l[i]
        j = i - g
        while j >= 0 and l[j] > tmp:
            l[j+g] = l[j]
            cnt += 1
            j -= g
        l[j+g] = tmp

    return l, cnt


def shell_sort(l, lg):
    tot = 0
    for g in lg:
        sl, cnt = insertion_sort(l, g)
        tot += cnt
    return sl, tot


if __name__ == '__main__':
    N = int(input())
    l = []
    for _ in range(N):
        l.append(int(input()))

    lg = [1]
    while True:
        gc = 3 * lg[-1] + 1
        if gc > N:
            break
        lg.append(gc)

    lg = lg[::-1]

    print(len(lg))
    print(' '.join(map(str, lg)))
    sl, tot = shell_sort(l, lg)
    print(tot)
    for e in sl:
        print(e)

