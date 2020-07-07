def selection_sort(n):
    c = 0
    r = n[:]
    l = len(r)
    for i in range(0, l):
        mini = i
        for j in range(i, l):
            if (r[j] < r[mini]):
                mini = j
        if mini != i:
            r[i], r[mini] = r[mini], r[i]
            c += 1
    return r, c

if __name__ == '__main__':
    limit = int(input())
    n = list(map(int, input().split()))[:limit]
    r, c = selection_sort(n)
    print(' '.join(map(str, r)))
    print(c)

