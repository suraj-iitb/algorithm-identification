from typing import Any,Sequence



def Insertion_sort(A:Sequence, N:int, g:int) -> None:
    global cnt
    for i in range(g, N):
        tmp = A[i]
        j = i - g
        while j >= 0 and A[j] > tmp:
            A[j + g] = A[j]
            j = j - g
            cnt += 1
        A[j + g] = tmp


def shell_sort(A:Sequence, N:int) -> None:
    global cnt
    cnt = 0
    g = []
    h = 1
    while h <= N:
        g.append(h)
        h = (3 * h) + 1
    g.reverse()
    m = len(g)
    print(m)
    print(' '.join(map(str, g)))

    for i in range(m):
        Insertion_sort(A, N, g[i])


n = int(input())
B = [int(input()) for i in range(n)]

shell_sort(B, n)
print(cnt)
[print(B[i]) for i in range(n)]
