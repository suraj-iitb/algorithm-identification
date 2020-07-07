def insertion_sort(array, g, result):
    for i in range(g, len(array)):
        v = array[i]
        j = i - g
        while j >= 0 and array[j] > v:
            array[j + g] = array[j]
            j -= g
            result['count'] += 1
        A[j + g] = v


def g_gene(n):
    yield 1
    for i in range(2, n):
        x = int((3 ** i - 1) / 2)
        if x < n:
            yield x
        else:
            raise StopIteration()


def shell_sort(array, result):
    result['count'] = 0
    G = list(reversed(list(g_gene(len(array)))))
    m = len(G)
    result['G'] = G
    result['m'] = m
    for i in range(m):
        insertion_sort(array, G[i], result)


if __name__ == '__main__':
    import sys
    n = int(sys.stdin.readline())
    A = []
    for _ in range(n):
        A.append(int(sys.stdin.readline()))
    result = {}
    shell_sort(A, result)
    print(result['m'])
    print(' '.join(map(str, result['G'])))
    print(result['count'])
    for a in A:
        print(a)
