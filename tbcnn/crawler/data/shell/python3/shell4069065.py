def insertionSort(a, n, g):
    global cnt
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j = j - g
            cnt = cnt + 1
        a[j+g] = v

def shellSort(a, n):
    global cnt
    global G
    global m
    cnt = 0
    G = [1]
    while 3 * G[0] + 1 <= n:
        G = [ 3*G[0]+1 ] + G
    m = len(G)
    for i in range(0, m):
        insertionSort(a, n, G[i])

n = int(input())
a = [int(input()) for i in range(0, n)]

shellSort(a, n)

print(m)
print(*G)
print(cnt)
for i in range(0, n):
    print(a[i])
