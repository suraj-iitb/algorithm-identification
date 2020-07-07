def shellsort(L, g):
    cnt = 0
    num = len(L)
    for i in range(g, num):
        v = L[i]
        j = i-g
        while j>= 0 and L[j] > v:
            L[j+g] = L[j]
            j = j -g
            cnt += 1
        L[j+g] =v
    return cnt

if __name__ == "__main__":
    num = int(input())
    l = []
    for i in range(num):
        t = int(input())
        l.append(t)
    #print(l)

    g = []
    i = 1
    while i <= len(l):
        g.append(i)
        i = i*3 +1
    g.reverse()
    count = 0
    for i in g:
        count += shellsort(l,i)
    print(len(g))
    print(*g)
    print(count)
    for i in l:
        print(i)

