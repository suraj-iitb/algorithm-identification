def insertion_sort(a, n, g):
    count = 0
    for i in range(g, n):
        j = i
        while j >= g and a[j-g] > a[j]:
                a[j-g], a[j] = a[j], a[j-g]
                j -= g
                count += 1

    return a, count


if __name__ == "__main__":
    import sys
    n = int(input())
    a = list(map(int, sys.stdin))
    count = 0

    G = [1]
    while n >= 3*G[-1] + 1:
        G.append(3*G[-1] + 1)

    for g in G[::-1]:
        a, cnt = insertion_sort(a, n, g)
        count += cnt

    print(len(G))
    print(*G[::-1])
    print(count)
    print(*a, sep="\n")
