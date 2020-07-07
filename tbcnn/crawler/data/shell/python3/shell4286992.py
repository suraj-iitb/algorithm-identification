def insertionSort(a,n,g):
    for i in range(g,n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j = j - g
            cnt[0] += 1
        a[j+g] = v
    return
    
def shellSort(a,n):
    h = 1
    while h <= n:
        g.append(h)
        h = 3*h + 1
    m[0] =  len(g)
    for i in range(m[0])[::-1]: insertionSort(a,n,g[i])
    return

if __name__ == "__main__":
    n = int(input())
    a = [int(input()) for _ in range(n)]
    g = []
    cnt = [0]
    m = [0]
    shellSort(a,n)
    print(m[0])
    print(" ".join(map(str,g[::-1])))
    print(cnt[0])
    print("\n".join(map(str,a)))
