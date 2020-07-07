def insertion_sort(A, n, g):
    cnt = 0
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j -= g
            cnt += 1
        A[j + g] = v
    return cnt
def shell_sort(A, n):
    cnt = 0
    G = [1]
    for i in range(1, 100):
        # https://web.archive.org/web/20170212072405/http://www.programming-magic.com/20100507074241/
        # 間隔
        delta = 4 ** i + 3 * 2 ** (i - 1) + 1
        if delta >= n:
            break
        G.append(delta)
    G.reverse()
    m = len(G)
    for i in range(m):
        cnt += insertion_sort(A, n, G[i])
    return m, G, cnt
n = int(input())
A = [int(input()) for _ in range(n)]
m, G, cnt = shell_sort(A, n)
print(m)
print(*G)
print(cnt)
print(*A, sep='\n')
