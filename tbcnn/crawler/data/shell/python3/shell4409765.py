n = int(input())
a = []
cnt = 0
for i in range(n):
    a.append(int(input()))

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

g = []
g.append(1)
m = 0
while g[m] < n:
    if n > 3 * g[m] + 1:
        m = m + 1
        g.append(3 * g[m-1] + 1)
    else:
        break
m = m + 1
g.reverse()

for i in range(m):
    insertionSort(a,n,g[i])

print(m)
print(*g)
print(cnt)
for i in range(n):
    print(a[i])


