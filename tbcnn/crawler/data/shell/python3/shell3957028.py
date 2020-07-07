
def insertion_sort(A, n, g):
    cnt = 0

    for i in range(g, n, 1):
        v = A[i]
        j = i - g

        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt = cnt + 1
        A[j+g] = v

    return cnt

def shell_sort(A, n):
    G = [1]
    j = 1
    while True:
        next_g = G[j-1]*3 + 1
        if next_g < n:
            G.append(next_g)
            j = j + 1
        else:
            break
    # print(G)

    G.reverse()
    print(len(G))
    G_str = map(str, G)
    print(' '.join(G_str))

    cnt = 0
    for g in G:
        cnt = cnt + insertion_sort(A, n, g)

    print(cnt)


N = int(input())
A = []
cnt = 0
# print(N)
for i in range(N):
    A.append(int(input()))
# print(N, A)

shell_sort(A, N)

for a in A:
    print(a)


