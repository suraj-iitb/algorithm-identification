def insertion_sort(A, g):
    cnt = 0
    for i in range(g, len(A)):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v
    return cnt

def shell_sort(A):
    cnt = 0
    h = 1
    G = []
    while h <= len(A)/2:
        G.append(h)
        h = 3 * h + 1
    if len(G) == 0:
        G.append(1)
    print(len(G))
    print(*G[::-1])
    for g_i in G[::-1]:
        cnt += insertion_sort(A, g_i)
    return cnt

if __name__ == '__main__':
    n = int(input())
    A = []
    for i in range(n):
        A.append(int(input()))

    print(shell_sort(A))
    for a in A:
        print(a)

