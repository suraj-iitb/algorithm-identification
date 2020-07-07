
def insertion(v, n, g):
    c = 0
    for i in range(g, n):
        k = v[i]
        j = i-g
        while j >= 0 and v[j] > k:
            v[j+g] = v[j]
            j -= g
            c += 1
        v[j+g] = k
    return c


n = int(input())
v = [int(input()) for _ in range(n)]

g = []
t = n//2
while t > 1:
    g.append(t)
    t //= 2
g.append(1)
m = len(g)
cnt = 0
for i in range(m):
    cnt += insertion(v, n, g[i])

print(m)
print(" ".join([str(_g) for _g in g]))
print(cnt)
for _v in v:
    print(_v)

