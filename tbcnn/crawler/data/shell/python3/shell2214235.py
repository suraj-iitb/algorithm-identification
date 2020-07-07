def insertion_sort(a, n, g):
    ct = 0
    for i in range(g, n):
        v = a[i]
        j = i-g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j -= g
            ct += 1
        a[j+g] = v
    return ct

def interval_list(n):
    m = 0
    gi= 1
    g = []
    while gi <= n:
        m += 1
        g.append(gi)
        gi = 4**m + 3 * 2**(m-1) + 1
        # good convergence
        # http://www.programming-magic.com/20100507074241/
    g.reverse()
    return g


if __name__ == "__main__":
    n = int(input())
    A = list(int(input()) for _ in range(n))
    G = interval_list(n)
    print(len(G))
    print(*G)
    
    ct= 0
    for i in G:
        ct += insertion_sort(A, n, i)
    print(ct)
    print(*A, sep="\n")
