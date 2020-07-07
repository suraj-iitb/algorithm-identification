def ins(a, n, g):
    global cnt
    for i in range(g, n):
        v = a[i]
        j = i -g
        while j >= 0 and a[j] >v:
            a[j+g] = a[j]
            j = j-g
            cnt += 1
            a[j+g] = v

def shell(a,n):
    global cnt
    cnt = 0 
    h = 1 
    G=[]
    while h <= n:
        G.append(h)
        h = 3*h +1
    G.reverse()
    m = len(G)
    print(m)
    print(" ".join(map(str, G)))

    for i in range(m):
        ins(a, n, G[i])

intn = int(input())
a = [int(input()) for i in range(intn)]

shell(a,intn)
print(cnt)
for w in a:
    print(w)
