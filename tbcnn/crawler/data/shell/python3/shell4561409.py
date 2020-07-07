import math

def insertion(a, n, g, cnt):
    for i in range(g, n):
        v = a[i]
        j  = i - g
        while v < a[j] and j >= 0:
            a[j+g] = a[j]
            j -= g
            cnt += 1
        else:
            a[j+g] = v
    else:
        return cnt

def shell(a, n):
    cnt = 0
    m = 9
    G = [100000, 11000, 1017, 107, 48, 25, 12, 7, 3, 1]
    for g in G:
        cnt = insertion(a, n, g, cnt)
    else:
        return cnt, m, G

def print_space(li, n):
    m = 0
    for i in range(len(li)-1):
        if li[i] <= n:
            print(li[i], end=' ')
            m += 1
    else:
        print(li[-1])
        m += 1
        return m

n = int(input())
a = [int(input()) for i in range(n)]


res = shell(a, n)

cnt = res[0]
G = res[2]

m = 0

for i in range(len(G)):
    if G[i] <= n:
        m += 1


print(m)
print_space(G, n)
print(cnt)
for i in a:
    print(i)



