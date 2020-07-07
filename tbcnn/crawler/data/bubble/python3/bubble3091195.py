def b_sort(n, l):
    cn = 0
    for i in range(n):
        for j in range(n-1, i, -1):
            if l[j] < l[j-1]:
                l[j], l[j-1] = l[j-1], l[j]
                cn += 1

    print(' '.join(map(str, l)))
    print(cn)


if __name__ == '__main__':
    N = int(input())
    L = list(map(int, input().split()))
    b_sort(N, L)

