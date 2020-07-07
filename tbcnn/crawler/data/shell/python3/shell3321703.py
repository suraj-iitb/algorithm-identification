def insertion_sort(A, n, g, cnt):
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            cnt += 1
            j -= g
        A[j+g] = v

    return A, cnt


def shell_sort(A, n):
    cnt = 0
    g = 1
    G = []
    while g <= n:
        G.append(g)
        g = 3 * g + 1
    G.reverse()
    m = len(G)

    for g in G:
        A, cnt = insertion_sort(A, n, g, cnt)

    return m, G, cnt, A


n = int(input().rstrip())
A = []
for _ in range(n):
    A.append(int(input().rstrip()))

m, G, cnt, A = shell_sort(A, n)

print(m)
print(' '.join(list(map(str, G))))
print(cnt)
print('\n'.join(list(map(str, A))))
