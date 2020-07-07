def insertion_sort(A, n, g):
    global cnt
    for i in range(g, n):
        val = A[i]
        j = i - g
        while j >= 0 and A[j] > val:
            A[j + g] = A[j]
            j = j - g
            cnt += 1
        A[j + g] = val


def shell_sort(A, n):
    global cnt
    cnt = 0
    G = []
    h = 1
    while h <= len(A):
        G.append(h)
        h = 3 * h + 1
    G.reverse()
    print(len(G))
    print(' '.join(map(str, G)))
    for i in range(0, len(G)):
        insertion_sort(A, n, G[i])


if __name__ == '__main__':
    n = int(input())
    l = [int(input()) for _ in range(n)]
    shell_sort(l, n)
    print(cnt)
    for i in l:
        print(i)

