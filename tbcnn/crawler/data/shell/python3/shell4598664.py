import sys

input = sys.stdin.readline


def main():
    n = int(input())
    A = [None] * n
    for i in range(n):
        A[i] = int(input())

    G = []
    g = 1
    while True:
        G.append(g)
        g = 3 * g + 1
        if g >= n:
            break
    G = G[::-1]
    m = len(G)
    cnt = 0

    for g in G:
        for i in range(g, n):
            v = A[i]
            j = i - g
            while j >= 0 and A[j] > v:
                A[j + g] = A[j]
                j -= g
                cnt += 1
            A[j + g] = v

    print(m)
    print(" ".join(map(str, G)))
    print(cnt)
    print("\n".join(map(str, A)))


if __name__ == "__main__":
    main()

