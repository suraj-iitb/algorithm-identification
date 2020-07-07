def s_sort(l):
    q = len(l)
    count = 0
    for i in range(q):
        minv = i
        for j in range(i+1, q):
            if l[j] < l[minv]:
                minv = j
        if minv != i:
            l[i], l[minv] = l[minv], l[i]
            count += 1
    print(' '.join(map(str, l)))
    print(count)


if __name__ == '__main__':
    N = int(input())
    ali = list(map(int, input().split()))
    s_sort(ali)

