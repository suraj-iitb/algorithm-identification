import math

def insertion_sort(A, n, g):
    global count
    for i in range(g, n):
        val = A[i]
        j = i - g
        while j >= 0 and A[j] > val:
            A[j + g] = A[j]
            j = j - g
            count += 1
        A[j+g] = val

def shell_sort(A, n):
    G = []
    h = 1
    while h <= n:
        G.append(h)
        h = 3 * h + 1
    G.reverse()
    for g in G:
        insertion_sort(A, n, g)

    return G

if __name__ == "__main__":
    n = int(input())
    A = [int(input()) for _ in range(n)]
    count = 0
    G = shell_sort(A, n)

    print(len(G))
    print(" ".join([str(g) for g in G]))
    print(count)
    for i in range(n):
        print(A[i])

