def insert_sort(L,n,g):
    cnt =0
    for i in range(g,n):
        v = L[i]
        j = i-g
        while j >= 0 and L[j] > v:
            L[j+g] = L[j]
            j = j-g
            cnt +=1
        L[j+g] = v
    return cnt


if __name__ == '__main__':
    n = int(input())
    L = []
    G = []
    h = 1
    cnt = 0
    for _ in range(n):
        L.append(int(input()))
    while 1:
        if h > n: break
        G.append(h)
        h = 3*h + 1
    G = G[::-1]
    for gap in G:
        cnt += insert_sort(L,n,gap)
    print(len(G))
    print(*G)
    print(cnt)
    for i  in range(n): 
        print(L[i])
