cnt = 0
def insertion_sort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v
def shell_sort(A, n):
    G = [1]
    for i in range(25):
        g = G[-1]*2+1
        if g > len(A)-1:
            break
        G.append(g)
    G.reverse()
    m = len(G)
    for g in G:
        insertion_sort(A, n, g)
    return m, G, A
n = int(input())
A = [int(input()) for _ in range(n)]
m, G, A = shell_sort(A, n)
print(m)
print(" ".join(map(str, G)))
print(cnt)
for a in A:
    print(a)
