import math


def insertion_sort(A, N, g, cnt):
    for i in range(g, N):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v
    return cnt


def shell_sort(A, N, cnt):
    G = []
    g = 1
    m = 0
    while g <= N:
        G.append(g)
        m += 1
        g = 3 * g + 1
    G.reverse()

    m = len(G)
    print(m)
    print(' '.join(map(str, G)))
    for g in G:
        cnt = insertion_sort(A, N, g, cnt)

    return cnt


if __name__ == "__main__":
    N = int(input())
    A = []
    for i in range(N):
        A.append(int(input()))

    cnt = 0
    cnt = shell_sort(A, N, cnt)

    print(cnt)
    for a in A:
        print(a)

