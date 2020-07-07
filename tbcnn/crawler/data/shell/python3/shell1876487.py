# Shell sort
def insertion_sort(A,n,g):
    cnt = 0
    for i in range(g, n):
        v = A[i]
        j = i-g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j-g
            cnt += 1
        A[j+g] = v
    return cnt
def shell_sort(A,n):
    cnt = 0
    # an+1 = an + 3**(n-1)
    # n ????¶????????????????????????§G?????????
    idx = 1
    G = [1]
    while True:
        nxt = G[idx-1] + 3**idx
        if nxt > n:
            break
        idx += 1
        G.append(nxt)
    G.reverse()
    m = len(G)
    print(m)
    print(' '.join(list(map(str, G))))
    for i in range(m):
        cnt += insertion_sort(A,n,G[i])
    print(cnt)
    for i in range(n): print(A[i])
n = int(input())
A = [int(input()) for _ in range(n)]
shell_sort(A,n)
