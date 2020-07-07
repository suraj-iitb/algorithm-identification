n = int(input())
a = [int(v) for v in input().split()]

vmax = 10000
b = [-1] * len(a)
c = [0] * (vmax + 1)
for v in a:
    c[v] += 1

for i in range(1, vmax + 1):
    c[i] = c[i] + c[i-1]

for j in range(n-1, -1, -1):
    b[c[a[j]] - 1] = a[j]
    c[a[j]] -= 1

print(' '.join([str(v) for v in b]))
