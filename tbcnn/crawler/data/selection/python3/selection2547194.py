n = int(input())
a = [int(x) for x in input().split()]
c = 0
for x in range(n):
    m = x
    for i in range(x, n):
        if a[i] < a[m]:
            m = i
    if x != m:
        a[x], a[m] = a[m], a[x]
        c += 1
print(*a)
print(c)
