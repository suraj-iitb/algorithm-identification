def insertion_sort(a, n, g):
    cnt = 0
    for i in range(1, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j + g], a[j] = a[j], a[j - g]
            j -= g
            cnt += 1

        a[j + g] = v
    return cnt


def shell_sort(a, n):
    g = []
    k = n - 1
    cnt = 0
    while k > 1:
        g.append(k)
        k //= 2
    g.append(1)
    for v in g:
        cnt += insertion_sort(a, n, v)

    return cnt, g


def main():
    n = int(input())
    a = [int(input()) for _ in range(n)]
    cnt, g = shell_sort(a, n)
    print(len(g))
    print(' '.join(map(str, g)))
    print(cnt)
    for i in a:
        print(i)


if __name__ == '__main__':
    main()

